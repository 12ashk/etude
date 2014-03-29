# /usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
from PyQt5.QtWidgets import *
import PyQt5.QtCore as QtCore

class Form(QWidget):
	def __init__(self, parent=None):
		super(Form, self).__init__(parent)
		nameLabel = QLabel("Name: ")
		self.nameline = QLineEdit()
		self.submitButton = QPushButton("Submit")

		buttonLayout1 = QVBoxLayout()
		buttonLayout1.addWidget(nameLabel)
		buttonLayout1.addWidget(self.nameline)
		buttonLayout2 = QHBoxLayout()
		buttonLayout2.addWidget(self.submitButton)

		self.submitButton.clicked.connect(self.submitContact)
		mainLayout = QGridLayout()
		mainLayout.addLayout(buttonLayout1, 0, 1)
		mainLayout.addLayout(buttonLayout2, 3, 3)

		self.setLayout(mainLayout)
		self.setWindowTitle("hello Qt")

	def submitContact(self):
			name = self.nameline.text()

			if name == "":
				QMessageBox.information(self, "Empty Field",
						"Please enter a name and adress.")
				return 
			else:
				QMessageBox.information(self, "Success",
						"Hello %s" % name)

if __name__ == '__main__':
	import sys
	app = QApplication(sys.argv)
	screen = Form()
	screen.show()
	sys.exit(app.exec_())

