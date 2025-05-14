
import random

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):
        print(f"Olá, meu nome é {self.name} e eu tenho {self.age} anos.")

def create_people(num_people):
    people = []
    for _ in range(num_people):
        name = f"Pessoa {len(people) + 1}"
        age = random.randint(18, 75)
        people.append(Person(name, age))
    return people

def main():
    num_people = 5
    people = create_people(num_people)

    for person in people:
        person.greet()

    oldest_person = min(people, key=lambda p: p.age)
    print(f"A pessoa mais velha é {oldest_person.name}, que tem {oldest_person.age} anos de idade.", end="")

if __name__ == "__main__":
    main()
