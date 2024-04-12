import string
import pandas
import random

dictionary_of_labelled_lists = {
    'slno':[],
    'userid':[],
    'password':[]
}

list_of_records = pandas.DataFrame(dictionary_of_labelled_lists)

for i in range(1, 73):
    pw = ''.join(random.choices(string.ascii_uppercase + string.digits, k=7))
    list_of_records.loc[i] = [str(i), "GECTCR_"+ str(i), pw]

print(list_of_records)
list_of_records.to_csv("random_passwords.csv", index=False)