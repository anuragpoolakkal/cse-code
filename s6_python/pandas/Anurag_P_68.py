import pandas as pd

def sort_rank():
    file_path = input("Enter path to CSV file: ")
    df = pd.read_csv(file_path)

    print("Columns available for sorting are:")
    for column in df.columns:
        print(column)

    field_to_sort = input("Enter field to sorted by: ")

    sorting_method = input("Enter sorting method (asc/desc): ")

    if field_to_sort not in df.columns:
        print("Field does not exist!")
        return

    sorted_df = df.sort_values(by=field_to_sort, ascending = False if sorting_method == 'desc' else True)
    sorted_df.to_csv('sorted_rank.csv', index=False)

    print(f"File sorted by {field_to_sort} and saved to sorted_rank.csv")

if __name__ == "__main__":
    sort_rank()



