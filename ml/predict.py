import joblib
import sys

model = joblib.load("ml/model.pkl")

experience = float(sys.argv[1])
publications = float(sys.argv[2])
difficulty = float(sys.argv[3])
success_rate = float(sys.argv[4])

prediction = model.predict([[experience,
                             publications,
                             difficulty,
                             success_rate]])

print(prediction[0])