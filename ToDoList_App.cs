
var list = new List<string>() { "go to park", "run at gym" };


 void Start() {
    Console.WriteLine("Choices for your To do list");
    Console.WriteLine("[S]ee all TODOs");
    Console.WriteLine("[A]dd a TODO");
    Console.WriteLine("[R]emove a TODO");
    Console.WriteLine("[E]xit");

    string userChoice = Console.ReadLine();

    switch(userChoice)
    {
        case "S":
        case "s":
            PrintSelectedOption("See all To Do's");
            Console.WriteLine("Your to do list items are: ");
            Console.WriteLine();
            int i = 1;
            foreach (string item in list)
            {
                Console.WriteLine(i + ". " + item);
                i++;
            }
            Console.WriteLine();
            Start();
            break;
        case "A":
        case "a":
            PrintSelectedOption("Add item to To Do list");
            Console.WriteLine();
            Console.WriteLine("please enter new item for to do list");
            string newItem = Console.ReadLine();
            list.Add(newItem);
            Console.WriteLine("You have entered: " + newItem);
            Console.WriteLine();
            Console.WriteLine("Item added, updated list is: ");
            foreach (string item in list)
            {
                Console.WriteLine(item);
                Console.WriteLine();
            }
            Start();
            break;
        case "R":
        case "r":
            PrintSelectedOption("Remove item from To Do list");
            Console.WriteLine();
            int r = 0;
            int x = 1;
            foreach (string item in list)
            {
                Console.WriteLine("Enter " + x + " to remove " + "\"" + list[r] + "\"");
                r++;
                x++;
                Console.WriteLine();
            }
            Console.WriteLine("please enter your selection number");
            Console.WriteLine();
            string removeItem = Console.ReadLine();
            int intRemoveItem = int.Parse(removeItem);
            var nixedItem = list[intRemoveItem - 1];
            list.Remove(list[intRemoveItem - 1]);
            Console.WriteLine("Item " + "\"" + nixedItem + "\"" + " has been removed");
            Console.WriteLine();
            int y = 1;
            Console.WriteLine("updated list is: ");
            foreach (string item in list)
            {
                Console.WriteLine();
                Console.WriteLine(y + ". " + item);
                y++;

            }
            Console.WriteLine();
            Start();
            break;
        case "E":
        case "e":
            PrintSelectedOption("Exit");
            break;
        default:
            PrintSelectedOption("Invalid Choice");
            Start();
            break;
    }

void PrintSelectedOption(string selectedOption) {
    Console.WriteLine("Selected Option: "+ selectedOption);
}
}
Start();

Console.WriteLine("press any key to exit");
Console.ReadKey();
