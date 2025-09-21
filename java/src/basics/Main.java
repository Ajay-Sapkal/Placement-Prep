package basics;

public class Main {
    public static void main(String[] args) {
        int[] marks = {97, 98, 95};
        try {
            System.out.println(marks[5]);
        }catch (Exception exception) {
            System.out.println("index is out of bond");
        }
        System.out.println("student name is ajay ");
    }

}
