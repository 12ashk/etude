class Person():
	def __init__(self, name, age):
		self.name = name
		self.age = age

	def __str__(self):
		return self.name + ' ' + str(self.age)
	
class Group():
	def __init__(self):
		self.persons = []
		self.index = 0

	def add(self, person):
		self.persons.append(person)
		return self

	def __iter__(self):
		return self
	
	def next(self):
		if self.index >= len(self.persons):
			self.index = 0
			raise StopIteration
		result = self.persons[self.index]
		self.index += 1
		return result

if __name__ == '__main__':
	group = Group().add(Person('Taro', 21)).add(
			Person('Hanako', 15)).add(
			Person('Jiro', 19))
	for person in group:
		print person
