#SET-1
print("""
      
      SET 1 
      
      """)
red_balls = 30
blue_balls = 20
green_balls = 10
total_balls = red_balls + blue_balls + green_balls

#drawing red ball
P_red = red_balls / total_balls
print(f"Probability of drawing a red ball: {P_red:.2f}")

#drawing blue ball
P_blue = blue_balls / total_balls
print(f"Probability of drawing a blue ball: {P_blue:.2f}")

#drawing blue ball(either blue or green)
P_blue_or_green = (blue_balls + green_balls) / total_balls
P_blue_given_blue_or_green = blue_balls / (blue_balls + green_balls)
print(f"Conditional probability of drawing a blue ball given that the ball is either blue or green: {P_blue_given_blue_or_green:.2f}")

#SET-2
print("""
      
      SET 2 
      
      """)

red_marbles = 15
blue_marbles = 25
yellow_marbles = 35
total_marbles = red_marbles + blue_marbles + yellow_marbles

#drawing yellow marble
P_yellow = yellow_marbles / total_marbles
print(f"Probability of drawing a yellow marble: {P_yellow:.2f}")

#drawing marble that is not blue
P_not_blue = (red_marbles + yellow_marbles) / total_marbles
print(f"Probability of drawing a marble that is not blue: {P_not_blue:.2f}")

#drawing red marble (either red or yellow)
P_red_given_red_or_yellow = red_marbles / (red_marbles + yellow_marbles)
print(f"Conditional probability of drawing a red marble given that the marble is either red or yellow: {P_red_given_red_or_yellow:.2f}")