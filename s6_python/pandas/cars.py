import pandas

dictionary_of_labelled_lists = {
    'cars': ['BMW', 'Volvo', 'Ford'],
    'passings': [3,7,2]
}

list_of_records = pandas.DataFrame(dictionary_of_labelled_lists)

list_of_records.loc[4] = ['Tata', 23]

for i in range(5, 10):
    list_of_records.loc[i] = ['tata', (23 + i)]

print(list_of_records)

list_of_records.to_csv("cars.csv")