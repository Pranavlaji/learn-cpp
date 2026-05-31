
import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    objectsIdentified = frame

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    blur = cv2.GaussianBlur(gray, (7,7), 0)

    edge = cv2.Canny(blur, 20, 100)

    kernel = np.ones((3,3), np.uint8)

    closed = cv2.morphologyEx(
    edge,
    cv2.MORPH_CLOSE,
    kernel
)

    contours, _ = cv2.findContours(
        closed,
        cv2.RETR_EXTERNAL,
        cv2.CHAIN_APPROX_SIMPLE
    )

    contours = sorted(
        contours,
        key=cv2.contourArea,
        reverse=True
    )

    for cnt in contours:

        area = cv2.contourArea(cnt)

        # ignore tiny contours
        if area < 5000:
            continue

    
        x,y,w,h = cv2.boundingRect(cnt)

        print(f"Pre:{area}")
        print(f"Ratio:{w/h}")

        if 1.9 <= w/h < 2.1:
            print(f"Post:{area}")

            cv2.drawContours(
                frame,
                [cnt],
                -1,
                (0,255,0),
                6
            )
            break

    cv2.imshow("Paper Detection", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
