package com.example.designpattern.prototype;

public class PrototypeTest {

    public static void main(String[] args) {

        BookShelf originBookShelf = new BookShelf();

        originBookShelf.addBook(new Book("A", "Apple"));
        originBookShelf.addBook(new Book("B", "Banana"));
        originBookShelf.addBook(new Book("C", "Cherry"));

        // 생성자를 활용해 객체 복사
        BookShelf newBookShelf = new BookShelf(originBookShelf);

        System.out.println("[The result of performing default] >>>");
        System.out.println("originBookShelf = " + originBookShelf);
        System.out.println("newBookShelf = " + newBookShelf);
        System.out.println();

        // 원본 수정
        originBookShelf.getOriginBookShelf().get(0).setAuthor("M");
        originBookShelf.getOriginBookShelf().get(0).setTitle("Mellon");

        System.out.println("[The result of performing a deep copy] >>>");
        System.out.println("originBookShelf = " + originBookShelf);
        System.out.println("newBookShelf = " + newBookShelf);
    }
}
