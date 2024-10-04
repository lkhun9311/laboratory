package com.example.laboratory.designpattern.prototype;

public class PrototypeTest {

    public static void main(String[] args) throws CloneNotSupportedException {

        BookShelf originBookShelf = new BookShelf();

        originBookShelf.addBook(new Book("A", "Apple"));
        originBookShelf.addBook(new Book("B", "Banana"));
        originBookShelf.addBook(new Book("C", "Cherry"));

        BookShelf newBookShelf = (BookShelf) originBookShelf.clone();

        System.out.println("[The result of performing default] >>>");
        System.out.println("originBookShelf = " + originBookShelf);
        System.out.println("newBookShelf = " + newBookShelf);
        System.out.println();

        originBookShelf.getOriginBookShelf().get(0).setAuthor("M");
        originBookShelf.getOriginBookShelf().get(0).setTitle("Mellon");

        System.out.println("[The result of performing a deep copy] >>>");
        System.out.println("originBookShelf = " + originBookShelf);
        System.out.println("newBookShelf = " + newBookShelf);
    }
}
