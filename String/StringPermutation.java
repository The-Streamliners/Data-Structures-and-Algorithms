import java.util.ArrayList;
import java.util.Scanner;

public class StringPermutation {
	
	/* 
	 * INPUT: man
	 * OUTPUT:	man	Man	mAn	MAn	maN	MaN	mAN	MAN	
	 */

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		permute(input);
	}
	
	private static void permute(String input) {

		int count = input.length();
		ArrayList<String> stringPermut = new ArrayList<String>();
		
		int max = 1 << count;
		input = input.toLowerCase();
		for (int i = 0; i < max; i++) {

			char combination[] = input.toCharArray();

			for (int j = 0; j < count; j++) {
				if (!(combination[j] >= 'a' && combination[j] <= 'z')
						&& !(combination[j] >= 'A' && combination[j] <= 'Z')) {
					continue;
				}

					if(((i >> j) &  1) == 1) {
	                    combination[j] = (char) (combination[j]-32);
	                }
			}
			String str = new String(combination);
			if(!stringPermut.contains(str)) {
				stringPermut.add(str);
			}
		}
		for(String s: stringPermut) {
			System.out.print(s+"\t");
		}
	}
}
