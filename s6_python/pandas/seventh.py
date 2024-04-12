import pandas as pd

df=pd.read_csv('rank.csv')
print(df)
df.insert(3,"Status","Verified")
for row_id in range(len(df)):
    for column_id in range(len(df.columns)):
        if (df.iat[row_id, (len(df_columns) - 2)]  == "Verified):
            df.iat[row_id, (len(df.columns) - 1)] = 1;
        else:
            df.iat[row_id, (len(df.columns) - 1)] = 0;
        print(df.iloc(row_id, column_id),'\t',end='')
    print('\n')