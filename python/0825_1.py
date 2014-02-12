# I do not make full program because of bothersome.
# coding: utf-8

class Report(object):
	def __init__(self):
		self.title = u'月次報告'
		self.text = [u'順調', u'最高']
	
	def output_report(self):
		self.output_start()
		self.output_head()
		self.output_body_start()
		self.output_body()
		self.output_body_end()
		self.output_end()
	
	def output_body(self):
		for line in self.text:
			self.output_line(line)

	def output_head(self):
		assert False , 'call 
