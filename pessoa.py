
import random

class Person:
    def __init__(self, name, age, contact):
        self.name = name
        self.age = age
        self.contact = contact

    def greet(self):
        print(f"Olá, meu nome é {self.name}, eu tenho {self.age} anos e meu contato é {self.contact}.")

def create_people(num_people):
    people = []
    for _ in range(num_people):
        name = f"Pessoa {len(people) + 1}"
        age = random.randint(0, 99)
        contact = "119"
        for i in range(8):
            contact += str(random.randint(0, 9))
        people.append(Person(name, age, contact))
    return people

def main():
    num_people = 5
    people = create_people(num_people)

    for person in people:
        person.greet()

    oldest_person = min(people, key=lambda p: p.age)
    print(f"A pessoa mais velha é {oldest_person.name}, que tem {oldest_person.age} anos de idade.")

if __name__ == "__main__":
    main()
