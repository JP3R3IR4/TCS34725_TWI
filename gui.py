from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QMessageBox, QLabel, QHBoxLayout, QMainWindow
import sys
from PyQt5.QtGui import QPixmap, QFont
from PIL import Image
import numpy as np
import serial
import threading

class MyWindow(QMainWindow):
        def __init__(self):
            super(MyWindow, self).__init__()
            self.setWindowTitle("TCS34725 RGB SENSOR GUI")
            self.setFixedSize(300, 100)
            self.R = 0
            self.G = 0
            self.B = 0
            self.rgb = 0
            self.ser = 0
            self.array = np.zeros([100, 100, 3], dtype=np.uint8)
            self.initUI()
            self.setSerial()
            thread1 = threading.Thread(target=self.serialk)
            thread1.start()

        def initUI(self):
            self.label_rgb = QLabel(self)
            self.label_img = QLabel(self)
            self.label_git = QLabel(self)
            self.array[:, :] = [self.R, self.G, self.B]
            self.img = Image.fromarray(self.array)
            self.img.save('testrgb.png')
            self.label_img.setPixmap(QPixmap('testrgb.png'))
            self.label_rgb.setText("[" + str(self.R) + "] [" + str(self.G) + "] [" + str(self.B) + "]")
            self.label_img.move(100, 50)
            self.label_rgb.move(100, 10)

        def updatergb(self):
            self.label_rgb.setText("[" + str(self.R) + "] [" + str(self.G) + "] [" + str(self.B) + "]")

        def updateimg(self):
            self.array[:, :] = [self.R, self.G, self.B]
            self.img = Image.fromarray(self.array)
            self.img.save('testrgb.png')
            self.label_img.setPixmap(QPixmap('testrgb.png').scaledToHeight(100))

        def setSerial(self):

            str = '/dev/cu.wchusbserial1430'
            self.ser = serial.Serial(str);

            # Init
            for i in range(11):
                self.rgb = self.ser.readline().strip()
                print(self.rgb)

        def serialk(self):
            while True:
                self.rgb = self.ser.readline().strip().decode('ascii').split(' ')
                self.R = self.rgb[0]
                self.G = self.rgb[1]
                self.B = self.rgb[2]

                self.updatergb()
                self.updateimg()

def window():
    app = QApplication(sys.argv)
    win = MyWindow()
    win.show()
    sys.exit(app.exec())

window()







