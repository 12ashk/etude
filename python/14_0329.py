# /usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import PyQt5.QtCore as QtCore
import PyQt5.QtGui as QtGui
import PyQt5.QtWidgets as QtWidgets

def on_click():
	print("Hello World")

def print_state(state):
	if state == 0:
		print("Unchecked")
	else:
		print("Checked")

def main():
	app = QtWidgets.QApplication(sys.argv)
	main_window = QtWidgets.QMainWindow()
	check_box = QtWidgets.QCheckBox("Check Box")
	hello_button = QtWidgets.QPushButton("Hello World!")
	hello_button.clicked.connect(check_box.toggle)
	check_box.stateChanged.connect(print_state)
	main_window.setCentralWidget(check_box)

#	main_window.setCentralWidget(hello_button)

	main_window.show()
	app.exec_()

if __name__ == '__main__':
	main()

