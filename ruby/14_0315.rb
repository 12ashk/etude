#! /usr/bin/env ruby
# coding: utf-8

class BinaryTreeNode
	attr_accessor :pare, :word, :left, :right
	def initialize(pare = nil, word)
		@word = word
		@pare = pare
		@left = nil
		@right = nil
	end

	def add(str)
		def _add(str)
			return 1 if @word == str
			if str < @word
				if @left == nil
					@left = BinaryTreeNode.new(self, str)
				else
					@left._add(str)
				end
			elsif str > @word
				if @right == nil
					@right = BinaryTreeNode.new(self, str)
				else
					@right._add(str)
				end
			end
		end
		if @pare != nil
			_find_root()._add(str)
		else
			_add(str)
		end
	end

	def _find_root()
		return self if @pare == nil
		@pare._find_root()
	end

	def printTree(order = 0)
		def preprint()
			print @word + "\n"
			@left.preprint() if @left != nil
			@right.preprint() if @right != nil
		end
		def midprint()
			@left.midprint() if @left != nil
			print @word + "\n"
			@right.midprint() if @right != nil
		end
		def postprint()
			@left.postprint() if @left != nil
			@right.postprint() if @right != nil
			print @word + "\n"
		end
		return 1 if @word == nil
		case order
		when 0 
			preprint()
		when 1
			midprint()
		when 2
			postprint()
		end
	end

	def subst(sstr, rstr)
		def _subst(sstr, rstr)
			if @left != nil
				l = @left.subst(sstr, rstr)
			else
				l = 0
			end
			if @right != nil
				r = @right.subst(sstr, rstr)
			else
				r = 0
			end
			if @word.gsub!(sstr, rstr) != nil
				return l+r+1
			end
			return l+r
		end
		c = _subst(sstr, rstr)
		sort()
		return c
	end

	def remove(str, f = 0)
		def _bfs(str, q)
			while(node = q.shift)
				if /#{str}/ =~ node.word
					q.clear
					node._delete()
					return 0
				end
				q.push(node.left) if node.left != nil
				q.push(node.right) if node.right != nil
			end
		end
		def _remove_all(str)
			@word = nil if /#{str}/ =~ @word
			left._remove_all(str) if @left != nil
			right._remove_all(str) if @right != nil
		end
		if f == 0
			_bfs(str, [self])
		elsif f == 1
			_remove_all(str)
			sort()
		end
	end

	def _delete()
		def change_node(node)
			if @pare != nil
				if @pare.right == self
					@pare.right = node
				else
					@pare.left = node
				end
				node.pare = @pare
			end
		end
		def find_max(node)
			return node if node.left == nil and node.right == nil
			find_max(node.right)
		end
		if @left == nil and @right == nil
			_delete_node()
			return 0
		elsif @left == nil
			change_node(@right)
			return 0
		elsif @right == nil
			change_node(@left)
			return 0
		end
		node = find_max(@left)
		node.pare.right = nil
		str = @word
		@word = node.word
		node._delete_node()
		node = _find_root()
		node.add(str)
		return 0
	end

	def _delete_node()
		@word = nil
		@left = nil
		@right = nil
		if @pare != nil
			@pare.right = nil if @pare.right == self
			@pare.left = nil if @pare.left == self
			@pare = nil
		end
	end

	def sort()
		def get_words()
			if @left != nil
				l = @left.get_words()
			else
				l = []
			end
			if @right != nil
				r = @right.get_words()
			else
				r = []
			end
			if @word == nil
				return l + r
			end
			return [@word] + l + r
		end
		q = get_words()
		delete_all()
		root = _find_root()
		root.word = q.shift
	while str = q.shift
		add(str) 
	end
	end

	def delete_all()
		@left.delete_all() if @left != nil
		@right.delete_all() if @right != nil
		@word = nil
		@pare = nil
		@left = nil
		@right = nil
	end
end

def main()
	rootNode = BinaryTreeNode.new(nil, 'asdf')
	rootNode.add('fdas')
	rootNode.add('das')
	rootNode.add('as')
	rootNode.add('s')
	rootNode.add('fdas')
	rootNode.add('fdaz')
	rootNode.add('fdds')
	rootNode.add('zdas')
	rootNode.printTree(0)
	print "\n\n"
	p rootNode.subst('da', 'zaaaa')
	rootNode.printTree(1)
end

if __FILE__ == $0
	main()
end
