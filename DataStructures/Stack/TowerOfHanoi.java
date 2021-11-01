public class HTowerOfHanoi {

    public static void towerOfHanoi(int disks, char source, char auxiliary, char destination) {

        // Base Case
        if (disks == 0){
            return;
        }
        if (disks == 1){
            System.out.println(source + " " + destination);
            return;
        }
        // move n-1 disks from source to auxiliary using destination as helper
        towerOfHanoi(disks-1, source, destination, auxiliary);
        // move nth disk from source to destination
        System.out.println(source + " " + destination);
        // move m-1 disks from auxiliary to destination using source as helper
        towerOfHanoi(disks-1, auxiliary, source, destination);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        towerOfHanoi(n, 'a', 'b', 'c');
    }

}
