#SET-1
print("""
      
      SET 1 
      
      """)

sensitivity = 0.93  # P(Breach Detected | Actually Breach)
specificity = 0.88  # P(No Breach Detected | Actually No Breach)
prevalence = 0.03   # P(Breach)

# P(Detected | No Breach)
p_detected_no_breach = 1 - specificity

# P(No Breach)
p_no_breach = 1 - prevalence

# P(Detected)
p_detected = (sensitivity * prevalence) + (p_detected_no_breach * p_no_breach)

# P(Breach | Detected)
p_breach_given_detected = (sensitivity * prevalence) / p_detected

print(f"The probability that the network activity is a breach given it was flagged: {p_breach_given_detected:.4f}")

#SET-2
print("""
      
      SET 2 
      
      """)
P_accident_given_rain = 0.7    # P(Accident | Rain)
P_accident_given_fog = 0.5     # P(Accident | Fog)
P_accident_given_rain_and_fog = 0.8  # P(Accident | Rain and Fog)

print(f"The probability that an accident occurs given both rain and fog: {P_accident_given_rain_and_fog:.4f}")
