from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QMessageBox, QLabel, QHBoxLayout
import numpy as np
app = QApplication([])
window = QWidget()
window.resize(300, 100)
window.setWindowTitle('TCS34725')

img = np.zeros([100,100,3],dtype=np.uint8)
img.fill(255) # or img[:] = 255

layout = QHBoxLayout()
layout.addWidget(QPushButton('Hello A'))
layout.addWidget(QPushButton('Hello B'))
layout.addWidget(QPushButton('Hello C'))

label = QLabel(window)
label.setText("SDIS Graphical User Interface")
label.move(65, 10)
label.show()

window.setLayout(layout)
window.show()
app.exec_()