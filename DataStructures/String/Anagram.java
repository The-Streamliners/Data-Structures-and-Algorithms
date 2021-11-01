import java.util.HashMap;
import java.util.Scanner;

public class Anagram {

    static boolean isAnagram(String a, String b) {
    	
    	char st1[] = a.toCharArray();
    	char st2[] = b.toCharArray();
    	HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    	for(Character c: st1) {
    		
    		if(map.containsKey(c)) {
    			map.put(c, map
    					.get(c)+1);
    		} else {
    			map.put(c, 1);
    		}
    	}
    	HashMap<Character, Integer> map1 = new HashMap<Character, Integer>();

    	for(Character c: st2) {
    		
    		if(map1.containsKey(c)) {
    			map1.put(c, map1.get(c)+1);
    		} else {
    			map1.put(c, 1);
    		}
    	}
    	
    	if(map.equals(map1)) {
    		return true;
    	} else 
    		return false;
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}