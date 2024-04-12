import pandas as pd

df = pd.read_csv('rank.csv')
df.insert(3,"Status","Verified")
for row_id in range(len(df)):
    for column_id in range(len(df.columns)):
        print(df.iloc(row_id, column_id),'\t',end='')
    print('\n')