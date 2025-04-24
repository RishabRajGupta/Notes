#SET-1
print("""
      
      SET 1 
      
      """)
P_Fatigue_given_Disorder = 0.65
P_JointPain_given_Disorder = 0.55
P_Disorder = 0.1
P_Fatigue_and_JointPain = 0.2

# P(Fatigue n Joint Pain | Disorder)
P_Fatigue_and_JointPain_given_Disorder = P_Fatigue_given_Disorder * P_JointPain_given_Disorder

# P(Disorder | Fatigue n Joint Pain)
P_Disorder_given_Fatigue_and_JointPain = (P_Fatigue_and_JointPain_given_Disorder * P_Disorder) / P_Fatigue_and_JointPain

print(f"The probability that the patient has the disorder given that they exhibit both fatigue and joint pain is {P_Disorder_given_Fatigue_and_JointPain:.4f}.")

#SET-2
print("""
      
      SET 2 
      
      """)
sensitivity = 0.91  # P(Churn Predicted | Actually Churn)
specificity = 0.86  # P(No Churn Predicted | Actually No Churn)
prevalence = 0.04   # P(Actually Churn)

p_no_churn = 1 - prevalence

p_churn_predicted_given_no_churn = 1 - specificity

p_churn_predicted = (sensitivity * prevalence) + (p_churn_predicted_given_no_churn * p_no_churn)

p_actual_churn_given_churn_predicted = (sensitivity * prevalence) / p_churn_predicted

print(f"The probability that a customer will actually churn given that the model has predicted churn: {p_actual_churn_given_churn_predicted:.4f}")
