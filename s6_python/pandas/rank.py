import pandas as pd

df = pd.read_csv('rank.csv')

print(df)

print("Printing head")
print(df.head)

print("Printing tail")
print(df.tail)

print("Printing entire content")
print(df.to_string())