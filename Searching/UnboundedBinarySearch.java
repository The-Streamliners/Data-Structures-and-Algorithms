public final class UnboundedBinarySearch {
    public static void main(String[] args) {
        int[] keys = { 5, 0, 1, 674, 531441, 249 };
        for (int key : keys) {
            int res = unboundedBinarySearch(key);
            if (res == -1) {
                System.out.println("No i exists for f(i) = " + key);
            } else {
                System.out.println("f(" + unboundedBinarySearch(key) + ") = " + key);
            }
        }
    }

    private static int unboundedBinarySearch(int key) {
        if (f(0) == key) {
            return 0;
        }
        int i = 1;
        while (f(i) < key) {
            i *= 2;
        }
        if (f(i) == key) {
            return i;
        }
        return binarySearch(key, i / 2, i - 1);
    }

    private static int binarySearch(int key, int low, int high) {
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (f(mid) == key) {
                return mid;
            }
            if (f(mid) < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    // Monotonically Increasing Function
    private static int f(int x) {
        return x * x * x;
    }
}
