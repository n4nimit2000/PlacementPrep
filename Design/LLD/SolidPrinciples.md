# SOLID Principles

**SOLID stands for:**
- S: Single Responsibility Principle
- O: Open/Closed Principle
- L: Liskov Substitution Principle
- I: Interface Segregation Principle
- D: Dependency Inversion Principle

*Advantages of SOLID Principles:*
- Avoid Duplicate Code
- Easy to Maintain
- Easy to Understand
- Flexible Software
- Reduce Complexity while building large systems


## 1. Single Responsibility Principle
A class should have only one responsibility - i.e. it should have only one reason to change.

*Advantages:*
- Testing: A class with one responsibility will have far fewer test cases and hence easy to test.
- Lower Coupling: Less functionality in a single class will have fewer dependencies.
- Organization – Smaller, well-organized classes are easier to search than monolithic ones.

### Example:

Consider the following `Marker` class:
```
public class Marker {
    String name, color;
    int price;

    public Marker(String name, String color, int price) {
        this.name = name;
        this.color = color;
        this.price = price;
    }
}
```

Now, consider another class `Invoice` which has a `Marker` class:
```
class Invoice {
    private Marker marker;
    private int quantity;

    public Invoice(Marker marker, int quantity) {
        this.marker = marker;
        this.quantity = quantity;
    }

    public int calculateTotal() {
        int price = marker.price * quantity;
        return price;
    }

    public void saveToDB() {
        // Saves the data into DB
    }

    public void printInvoice() {
        // Prints the Invoice
    }
}
```

The above `Invoice` class is responsible for the following:
- Calculating the total price for marker
- Saving the data to DB
- Printing the invoice

Hence, this design is not following the *Single Responsibility Principle*.

We should rather create the following classes to obey the *Single Responsiblity Principle*:
```
// This class is only responsible for generating the total
class Invoice {
    private Marker marker;
    private int quantity;

    public Invoice(Marker marker, int quantity) {
        this.marker = marker;
        this.quantity = quantity;
    }

    public int calculateTotal() {
        int price = marker.price * quantity;
        return price;
    }
}

// This class is only responsible for saving the data into DB
class InvoiceDao {
    private Invoice invoice;

    public InvoiceDao(Invoice invoice) {
        this.invoice = invoice;
    }

    public void saveToDB() {
        // Saves the data into DB
    }
}


// This class is only responsible for printing the invoice
class InvoicePrinter {
    private Invoice invoice;

    public InvoicePrinter(Invoice invoice) {
        this.invoice = invoice;
    }

    public void printInvoice() {
        // Prints the Invoice
    }
}
```


## 2. Open/Closed Principle
Classes should be open for extension but closed for modification. In doing so, we stop ourselves from modifying existing code and causing potential new bugs.

### Example:
Consider the `InvoiceDao` class we created above. Let's say we have got a new requirement for saving the data into the file (we were already saving the data into the DB) and we make the following code changes:

```
class InvoiceDao {
    private Invoice invoice;

    public InvoiceDao(Invoice invoice) {
        this.invoice = invoice;
    }

    public void saveToDB() {
        // Saves the data into DB
    }

    public void saveToFile() {
        // We have created a new function which saves the data into File
    }
}
```

The above design does not follow the *Open/Closed Principle* because we are modifying an existing code - which makes it prone to bugs. We should instead try extending the new requirement by doing the following:

```
interface InvoiceDao {
    public void save(Invoice invoice);
}

class DatabaseInvoiceDao implements InvoiceDao {
    @Override
    public void save(Invoice invoice) {
        // Saves data to DB
    }
}

class FileInvoiceDao implements InvoiceDao {
    @Override
    public void save(Invoice invoice) {
        // Save data to File
    }
}
```

## 3. Liskov Substitution Principle
If class A is a subtype of class B, we should be able to replace object of B with A without disrupting the behavior of our program - this basically means that subclasses should extend the capability of parent class and not narrow it down.

### Example:
```
interface Bike {
    public void turnOnEngine();
    public void accelerate();
}

class MotorCycle implements Bike {
    private Engine engine;
    private int speed;

    public void turnOnEngine() {
        engine.on();
    }

    public void accelerate() {
        speed += 10;
    }
}

class Bicycle implements Bike {
    private int speed;

    public void turnOnEngine() {
        // A Bicycle does not have an engine. Hence this would throw exception
        throw new AssertionError("There is no engine in Bicycle");
    }

    public void accelerate() {
        speed += 2;
    }
}
```
The above design is a violation to *Liskov Substitution Principle* since the `Bicycle` class narrowed down the capability (i.e. turnOnEngine()) which it received from it's parent (i.e. `Bike` class). 

We should better design for such scenarios by ensuring that the **parent class has only generic capabilities and delegate addtional capabilities to its sub-classes**. A better design for the above scenario would be:

```
interface Bike {
    public void accelerate();
}

interface EngineBike extends Bike {
    public void turnOnEngine();
}

class MotorCycle implements EngineBike {
    private Engine engine;
    private int speed;

    public void turnOnEngine() {
        engine.on();
    }

    public void accelerate() {
        speed += 10;
    }
}

class Bicycle implements Bike {
    private int speed;

    public void accelerate() {
        speed += 2;
    }
}
```

## 4. Interface Segregation
Larger interfaces should be split into smaller ones. By doing so, we can ensure that client does not implement unnecessary functions that they do not need.

### Example:
Here is an interface that outlines what a restaurant employee does:

```
interface RestaurantEmployee {
    public void washDishes();
    public void serveCustomers();
    public void cookFood();
}
```
Now, if are trying to implement this `RestaurantEmployee` interface based on the various employees (Waiter, Chef and  Helper), it would look something like this:

```
class Waiter implements RestaurantEmployee {
    public void washDishes() {
        // Not my job
    }

    public void serveCustomers() {
        System.out.println("Serving the customer..");
    }

    public void cookFood() {
        // Not my job
    }
}

class Chef implements RestaurantEmployee {
    public void washDishes() {
        // Not my job
    }

    public void serveCustomers() {
        // Not my job
    }

    public void cookFood() {
        System.out.println("Cooking the food..");
    }
}

class Helper implements RestaurantEmployee {
    public void washDishes() {
        System.out.println("Washing the dishes..");
    }

    public void serveCustomers() {
        // Not my job
    }

    public void cookFood() {
        // Not my job
    }
}
```
The above design violates the *Interface Segregation Principle* since each of the classes (Waiter, Chef and Helper) are implementing unnecessary functions that they do not need.

We should rather **segregate the interfaces in such a manner that no class is implementing unnecessary functions that they do not need**. Similar to below:

```
interface WaiterInterface {
    public void serveCustomers();
    public void takesOrder();
}

interface ChefInterface {
    public void cookFood();
    public void decideMenu();
}

class Waiter implements WaiterInterface {
    public void serveCustomers() {
        System.out.println("Serving the customer..");
    }

    public void takesOrder() {
        System.out.println("Taking the order..");
    }
}
```

## 5. Dependency Inversion Principle
Class should depend on interfaces rather than concrete classes.

### Example:
Consider an interface `Keyboard` which has two classes implementing it: `WiredKeyboard` and `BluetoothKeyboard`. Also, consider another interface `Mouse` which has two classes implementing it: `WiredMouse` and `BluetoothMouse`. Here is a sample code:

```
interface Keyboard {
    public void type();
}

public class WiredKeyboard implements Keyboard {
    public void type() {
        System.out.println("Typed on WiredKeyboard");
    }
}

public class BluetoothKeyboard implements Keyboard {
    public void type() {
        System.out.println("Typed on BluetoothKeyboard");
    }
}

interface Mouse {
    public void click();
}

public class WiredMouse implements Mouse {
    public void click() {
        System.out.println("Clicked on WiredMouse");
    }
}

public class BluetoothMouse implements Mouse {
    public void click() {
        System.out.println("Clicked on BluetoothMouse");
    }
}
```

Now if we create a `Macbook` class which currently only uses `WiredKeyboard` and `WiredMouse`:
```
public class Macbook {
    private final WiredKeyboard keyboard;
    private final WiredMouse mouse;

    public Macbook() {
        keyboard = new WiredKeyboard();
        mouse = new WiredMouse();
    }
}
```
This code will work, and we’ll be able to use the WiredKeyboard and WiredMouse freely within our Macbook class. But we have tightly coupled `Macbook` class to `WiredKeyboard` and `WiredMouse` classes. Now we will run into a problem if a need arises for `Macbook` class to use `BluetoothKeyboard` or `BluetoothMouse`. Hence, we should decouple our `Macbook` from the `WiredKeyboard` and `WiredMouse` by adding a more general `Keyboard` and `Mouse` interface and using this in our class:
```
public class Macbook {

    private final Keyboard keyboard;
    private final Mouse mouse;

    public Macbook(Keyboard keyboard, Mouse mouse) {
        this.keyboard = keyboard;
        this.mouse = mouse;
    }
}
```
Here, we’re using the dependency injection pattern to facilitate adding the `Keyboard` and `Mouse` dependency into the `Macbook` class. Now our classes are decoupled and communicate through the `Keyboard` and `Mouse` abstraction. If we want, we can easily switch out the type of `keyboard`/`mouse` in our `Macbook` with a different implementation of the interface.
