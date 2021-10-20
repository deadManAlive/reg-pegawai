from faker import Faker
from datetime import date,datetime
import pandas as pd
from random import seed,randint,choice
import sys

number_of_employees = int(sys.argv[1]) if len(sys.argv) > 1 else 20

print("Membuat {} data dummy...".format(number_of_employees))

fake = Faker('id_ID')

list_of_employees = []

# Age generator
di = datetime.strptime(f'30/9/1965', '%d/%m/%Y')
de = datetime.strptime(f'21/5/1998', '%d/%m/%Y')
dn = date.today()

seed(1)

for individual in range(number_of_employees):
    # NIP forgery
    nip = str(randint(11111,99999)) + str(fake.ean(length=13))

    # Gender forgery
    gender = choice(["L", "P"])

    # Name forgery
    fname = fake.first_name_male() if gender == "L" else fake.first_name_female()
    mname = fake.first_name() if gender == "P" else fake.first_name_male()
    lname = fake.last_name() if gender == "P" else fake.last_name_male()

    oname = ' '.join(
        choice(
            [
                [fname, mname, lname],
                [fname, lname],
                [fname, mname],
                [fname]
            ]
        )
    )

    # Rank forgery
    gol = choice([1, 2, 3, 4])
    subgol = choice(["A", "B", "C", "D"]) if gol != 4 else choice(["A", "B", "C", "D", "E"]) # trial
    supgol = '-'.join([str(gol), subgol])

    list_of_employees.append([nip, oname, gender, supgol])

list_of_employees = sorted(list_of_employees, key=lambda x: x[0])

employees_df = pd.DataFrame(list_of_employees, columns=['NIP', 'Nama', 'Kelamin', 'Golongan'])

pd.set_option('display.max_columns', None)

employees_df.to_csv('data_pegawai.csv', index=False, header=True, sep=';')