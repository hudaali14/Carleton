package comp1406t5;

/** A simple tester for the mail/letter/parcel classes */
public class TestMail{

	public static void main(String[] args){
		Date today = new Date(2019, 02, 02);

		Letter letter = new Letter("Animal Farm", text, today);
		System.out.println(letter);
		letter.delivered(new Date(2019, 02, 03));
		System.out.println(letter);

		Stuff stuff = new Stuff("some things");
		Parcel parcel = new Parcel("Office Supplies", stuff, 12.15, today);
		System.out.println(parcel);
		parcel.delivered(new Date(2019, 02, 03), "damaged");
		System.out.println(parcel);


	}


	protected static String text = "Mr. Jones, of the Manor Farm, had locked "
	+ "the hen-houses for the night, but was too drunk to remember to shut "
	+ "the pop-holes. With the ring of light from his lantern dancing from "
	+ "side to side, he lurched across the yard, kicked off his boots at the "
	+ "back door, drew himself a last glass of beer from the barrel in the "
	+ "scullery, and made his way up to bed, where Mrs. Jones was already snoring.";
}
