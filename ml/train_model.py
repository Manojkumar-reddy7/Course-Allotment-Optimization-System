import pandas as pd
from sklearn.linear_model import LinearRegression
import joblib

# Load dataset
data = pd.read_csv("../data/training_data.csv")

# Features
X = data[["experience","publications","course_difficulty","success_rate"]]

# Target
y = data["score"]

# Train model
model = LinearRegression()
model.fit(X, y)

# Save model
joblib.dump(model, "model.pkl")

print("Model trained and saved successfully!")