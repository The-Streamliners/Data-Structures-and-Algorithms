import java.util.* ; 

public class AssigningMiceToHoles 
{ 
	public static void main(String[] args) 
	{ 
		AssigningMiceToHoles miceAssigns = new AssigningMiceToHoles(); 
		ArrayList<Integer> mice = new ArrayList<Integer>(); 
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the number of Mice/Holes: ");
		int numberOfMice = input.nextInt();
		System.out.println("Enter the postions of mice: ");
		for (int i = 0; i < numberOfMice; i++) {
			int miceAdd = input.nextInt();
			mice.add(miceAdd);
		}
		ArrayList<Integer> holes= new ArrayList<Integer>(); 
		System.out.println("Enter the postions of mice: ");
		for (int i = 0; i < numberOfMice; i++) {
			int holesAdd = input.nextInt();
			holes.add(holesAdd);
		}
		System.out.println("The last mouse gets into " + "the hole in time: " + miceAssigns.assignHole(mice, holes)); 
		input.close();
	}
	
	public int assignHole(ArrayList<Integer> mice, 
						ArrayList<Integer> holes) 
	{ 
		if (mice.size() != holes.size()) 
		return -1; 

		Collections.sort(mice); 
		Collections.sort(holes); 

		int miceSize = mice.size(); 

		int maxTime = 0; 
		
		for (int i=0; i<miceSize; i++) 
			if (maxTime < Math.abs(mice.get(i)-holes.get(i))) {
				maxTime = Math.abs(mice.get(i)-holes.get(i)); 
			}

		return Math.abs(maxTime); 
	} 
 
} 
