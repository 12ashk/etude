height = float(raw_input("input your height[cm]: "))
weight = float(raw_input("input your weight[kg]: "))

standard_weight = ((height / 100) ** 2) * 22
fat = (weight / standard_weight - 1) * 100

print "your standard weight is", standard_weight, "kg"
print "your fatness is", fat, "%"

if fat > 10:
    print "you are too fat"

elif fat < -10:
    print "you are too skinny"

else:
    print "you are standard"
