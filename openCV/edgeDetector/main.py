import cv2
import numpy as np


cap = cv2.VideoCapture(0)

def nothing(x):
    pass

cv2.namedWindow('window')
cv2.createTrackbar(
    'Threshold1',
    'window',
    100,
    500,
    nothing,
)
cv2.createTrackbar(
    'Threshold2',
    'window',
    100,
    500,
    nothing,
)

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray,(5,5),0)
    t1 = cv2.getTrackbarPos('Threshold1','window')
    t2 = cv2.getTrackbarPos('Threshold2','window')
    object = cv2.Canny(blur,t1,t2)
    comparision = np.hstack((blur,object))
    cv2.imshow('Comparision',comparision)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()