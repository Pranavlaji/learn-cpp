import cv2
import numpy as np
def find_hsv(event,x,y,flags,param):
    if event == cv2.EVENT_LBUTTONUP:
        print(hsv[y,x])


cap = cv2.VideoCapture(0)
lower = (110,130,150)
upper = (150,255,253)



while True:
    ret, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv,lower,upper)
    blur = cv2.GaussianBlur(mask,(5,5),0)

    
    contours, _ = cv2.findContours(
        blur,
        cv2.RETR_EXTERNAL,
        cv2.CHAIN_APPROX_SIMPLE
    )

    objectsIdentified = cv2.drawContours(frame, contours,-1, (0,255,0), 2)
    cv2.imshow("Main",objectsIdentified)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()