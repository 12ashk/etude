import sys
import os
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

class Notepad(QMainWindow):
	def __init__(self):
		super(Notepad, self).__init__()
		self.initUI()
	
	def initUI(self):
		openAction = QAction('Open', self)
		openAction.setShortcut('Ctrl+O')
		openAction.setStatusTip('Open a pad')
		openAction.triggered.connect(self.openFile)

		closeAction = QAction('Close', self)
		closeAction.setShortcut('Ctrl+Q')
		closeAction.setStatusTip('Close a pad')
		closeAction.triggered.connect(self.close)

		closefAction = QAction('File Close', self)
		closefAction.setStatusTip('Close File')
		closefAction.triggered.connect(self.closeFile)

		menubar = self.menuBar()
		fileMenu = menubar.addMenu('&File')
		fileMenu.addAction(openAction)
		fileMenu.addAction(closeAction)
		fileMenu.addAction(closefAction)

		self.textEdit = QTextEdit(self)
		self.textEdit.setFocus()
		self.textEdit.setReadOnly(True)

		self.resize(700, 800)
		self.setWindowTitle('Notepad')
		self.setCentralWidget(self.textEdit)
		self.show()

	def openFile(self):
		filename, _ = QFileDialog.getOpenFileName(self, 'Open File', os.getenv('HOME'))

		fh = ''
		if QFile.exists(filename):
			fh = QFile(filename)

		if not fh.open(QFile.ReadOnly):
			QtGui.qApp.quit()

		data = fh.readAll()
		codec = QTextCodec.codecForUtfText(data)
		unistr = codec.toUnicode(data)

		tmp = ('&Notepad: %s' % filename)
		self.setWindowTitle(tmp)

		self.textEdit.setText(unistr)

	def closeFile(self):
		self.textEdit.clear()

def main():
	app = QApplication(sys.argv)
	notepad = Notepad()
	sys.exit(app.exec_())

if __name__ == '__main__':
	main()





