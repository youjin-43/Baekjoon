using System;

// ===============================
// class: 참조 타입 Reference Type
// ===============================
class PersonClass
{
    public string Name;
    public int Age;
}

// ===============================
// struct: 값 타입 Value Type
// ===============================
struct PersonStruct
{
    public string Name;
    public int Age;
}

class Program
{
    static void Main()
    {
        Console.WriteLine("===== 1. class 복사 테스트 =====");

        PersonClass classA = new PersonClass();
        classA.Name = "민정";
        classA.Age = 25;

        // class는 참조 타입이므로,
        // classB에는 객체 자체가 복사되는 것이 아니라
        // classA가 가리키는 객체의 주소, 즉 참조가 복사됨
        PersonClass classB = classA;

        // classB를 수정하면 같은 객체를 보고 있는 classA도 영향을 받음
        classB.Age = 30;

        Console.WriteLine($"classA Age: {classA.Age}");
        Console.WriteLine($"classB Age: {classB.Age}");

        Console.WriteLine();
        Console.WriteLine("===== 2. struct 복사 테스트 =====");

        PersonStruct structA = new PersonStruct();
        structA.Name = "민정";
        structA.Age = 25;

        // struct는 값 타입이므로,
        // structB에는 structA의 값 자체가 복사됨
        PersonStruct structB = structA;

        // structB를 수정해도 structA에는 영향을 주지 않음
        structB.Age = 30;

        Console.WriteLine($"structA Age: {structA.Age}");
        Console.WriteLine($"structB Age: {structB.Age}");

        Console.WriteLine();
        Console.WriteLine("===== 3. 메서드에 전달했을 때 차이 =====");

        PersonClass classC = new PersonClass();
        classC.Name = "Class";
        classC.Age = 10;

        PersonStruct structC = new PersonStruct();
        structC.Name = "Struct";
        structC.Age = 10;

        ChangeClassAge(classC);
        ChangeStructAge(structC);

        // class는 참조가 전달되므로 내부 필드 변경이 원본에 반영됨
        Console.WriteLine($"classC Age after method: {classC.Age}");

        // struct는 값이 복사되어 전달되므로 원본에는 반영되지 않음
        Console.WriteLine($"structC Age after method: {structC.Age}");

        Console.WriteLine();
        Console.WriteLine("===== 4. ref를 사용한 struct 전달 =====");

        ChangeStructAgeByRef(ref structC);

        // ref를 사용하면 struct도 원본 자체를 수정할 수 있음
        Console.WriteLine($"structC Age after ref method: {structC.Age}");

        Console.WriteLine();
        Console.WriteLine("===== 5. null 가능 여부 =====");

        // class는 참조 타입이므로 null을 가질 수 있음
        PersonClass nullableClass = null;

        if (nullableClass == null)
        {
            Console.WriteLine("class는 null이 가능함");
        }

        // struct는 기본적으로 null을 가질 수 없음
        // 아래 코드는 컴파일 에러 발생
        // PersonStruct nullableStruct = null;

        // 대신 Nullable<T> 또는 ? 문법을 사용하면 null 가능
        PersonStruct? nullableStruct = null;

        if (nullableStruct == null)
        {
            Console.WriteLine("struct는 기본적으로 null 불가, 하지만 ?를 붙이면 null 가능");
        }
    }

    static void ChangeClassAge(PersonClass person)
    {
        // class는 참조 타입이므로
        // person은 원본 객체를 가리킴
        person.Age = 99;
    }

    static void ChangeStructAge(PersonStruct person)
    {
        // struct는 값 타입이므로
        // person은 원본의 복사본임
        person.Age = 99;
    }

    static void ChangeStructAgeByRef(ref PersonStruct person)
    {
        // ref를 사용하면 복사본이 아니라 원본을 직접 수정함
        person.Age = 77;
    }
}