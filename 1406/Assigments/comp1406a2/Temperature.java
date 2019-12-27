package comp1406a2;

/**
 * A class to represent temperature (with a value and scale).
 *
 * COMP 1406
 * Winter 2019
 * Assignment 2
 */

public class Temperature{

	//temp hold the temperature
	private double temp;

	//scale hold scale object
	private Scale scale;
	

	/** Initializes a temperature object with given value in Celsius
	*  <p>
	*  If the initial temperature is less than -273.15C then the temperature
	*  object will be initialized with -273.15C.
	*
	* @param temp is the initial temperature in Celsius.
	*/
	public Temperature(double temp){

		//if temperature is lower than absolute zero in celsius sets the temperature to absolute zero and scale in celsius
		if (temp<(-273.15)){
			this.temp=-273.15;
			this.scale=Scale.CELSIUS;
		
		//sets temperature and scale in celsius
		}else{
			this.temp=temp;
			this.scale=Scale.CELSIUS;
		}
	}


	/** Initializes a temperature object with given value using the specified scale
	* <p>
	* If the temperature is lower than absolute zero, in the given scale,
	* then set the temperature to absolute zero (in that scale).
	* <p>
	* Usage: new Temperature(12.3, Scale.KELVIN)
	*
	* @param temp is the initial temperature in the scale provided in
	*        the second argument.
	* @param scale is the scale of initial temperature and must be a constant
	*        defined in the Scale enum type.
	*/
	public Temperature(double temp, Scale scale){

		//sets scale in celsius
		this.scale=scale;

		//if temperature is lower than absolute zero in celsius sets the temperature to absolute zero and scale in celsius else sets temp and scale
		if (scale==Scale.CELSIUS){
			if (temp<(-273.15)){
				this.temp=-273.15;
			}else{
				this.temp=temp;
			}
		
		//if temperature is lower than absolute zero in celsius sets the temperature to absolute zero and scale in fahrenheit else sets temp and scale
		}else if (scale==Scale.FAHRENHEIT){
			if (temp<(-459.67)){
				this.temp=-459.67;
			}else{
				this.temp=temp;
			}
		
		//if temperature is lower than absolute zero in celsius sets the temperature to absolute zero and scale in kelvin else sets temp and scale
		}else{
			if (temp<0){
				this.temp=0;
			}else{
				this.temp=temp;
			}
		}
	}


	/** Initializes a new temperature object that is a copy of the
	*  temperature object parameter.
	*
	* That is, it makes a new object that is a copy of the input object.
	*
	* @param temp is a non-null temperature object
	*/
	public Temperature(Temperature temp){

		//holder for character
		char holder;

		//gets temp
		this.temp=temp.getTemp();

		//sets holder to scale
		holder=temp.getScale();

		//holder is k, sets scale to kelvin
		if (holder=='K'){
			this.scale=Scale.KELVIN;
		
		//holder is f, sets scale to fahrenheit
		}else if(holder=='F'){
			this.scale=Scale.FAHRENHEIT;

		//holder is c, sets scale to celsius
		}else{
			this.scale=Scale.CELSIUS;
		}
	}


	/** getter for the scale
	* <p>
	* The output of this getter method must always be the first letter of one
	* of the names in the Scales enum class. It must be the upper case letter.
	* <p>
	* Example: t = new Temperature(12.3, Scale.KELVIN);
	*          t.getScale() will then output 'K'
	*
	* @return the first letter (in upper case) of the string representation of the
	*         current scale of this object.
	*/
	public char getScale(){

		//if scale is celsius, fahrenheit or kelvin returns the letter verison of it
		if (this.scale==Scale.CELSIUS){
			return 'C';
		}else if(this.scale==Scale.FAHRENHEIT){
			return 'F';
		}else{
			return 'K';
		}		
	}


	/** getter for the temperature
	*
	* @return the temperature of the object using the current scale
	*/
	public double getTemp(){

		//get temp
		return this.temp;
	}


	/** setter for scale
	*
	* @param scale is the new scale of the temperature and must be
	*        a constant from the Scale enum type. The next time you
	*        call getTemp(), the temperature will be output in this scale.
	* @return a reference to this object.
	*/
	public Temperature setScale(Scale scale){

		//sets scale from current scale to desire scale and converts temp to desire scale temp
		if(scale==scale.FAHRENHEIT && this.scale==Scale.CELSIUS){
			this.temp=(this.temp*(9.00/5.00))+32;
			this.scale=scale.FAHRENHEIT;
		}else if(scale==scale.FAHRENHEIT && this.scale==Scale.KELVIN){
			this.temp=(this.temp*(9.00/5.00))-459.67;
			this.scale=scale.FAHRENHEIT;
		}else if(scale==scale.CELSIUS && this.scale==Scale.FAHRENHEIT){
			this.temp=(this.temp-32)*(5.00/9.00);
			this.scale=scale.CELSIUS;
		}else if(scale==scale.CELSIUS && this.scale==Scale.KELVIN){
			this.temp=this.temp-273.15;
			this.scale=scale.CELSIUS;
		}else if(scale==scale.KELVIN && this.scale==Scale.FAHRENHEIT){
			this.temp=(this.temp+459.67)*(5.00/9.00);
			this.scale=scale.KELVIN;
		}else{
			if(scale==scale.KELVIN && this.scale==Scale.CELSIUS){
				this.temp=this.temp+273.15;
				this.scale=scale.KELVIN;
			}
		} 
		return this;  // do NOT change this return statement.
	}


	/** setter for temperature
	*
	* @param temp is the new temperature (in the object's current scale)
	* @return a reference to this object.
	*/
	public Temperature setTemp(double temp){
		
		//sets temp
		this.temp=temp;
		return this;  // do NOT change this return statement.
	}

	/** setter for temperature
	*
	* @param temp is the new temperature
	* @param scale is the scale of the new temperature. It must be
	*        a constant from the Scale enum type.
	* @return a reference to this object.
	*/
	public Temperature setTemp(double temp, Scale scale){

		//if temperature is lower than absolute zero in celsius sets the temperature to absolute zero and scale in celsius
		if (scale==Scale.CELSIUS && temp<(-273.15)){
			this.temp=-273.15;
			this.scale=scale;

		//if temperature is lower than absolute zero in celsius sets the temperature to absolute zero and scale in fahrenheit
		}else if (scale==Scale.FAHRENHEIT && temp<(-459.67)){
			this.temp=-459.67;
			this.scale=scale;
		}else{

			//if temperature is lower than absolute zero in celsius sets the temperature to absolute zero and scale in kelvin
			if (scale==Scale.KELVIN && temp<(0)){
				this.temp=0;
				this.scale=scale;

			//sets temp from current to new temp and scale from current to new scale
			}else{
				this.scale=scale;
				this.temp=temp;
			}
		}
		return this;  // do NOT change this return statement.
	}

	/** setter for temperature
	*
	* @param temp is the new temperature.
	* @param scale is a string representing one of the three scales.
	* @return a reference to this object.
	*/
	public Temperature setTemp(double temp, String scale){

		//check if the first letter capitalized is equal to C
		if (Character.toUpperCase(scale.charAt(0))=='C') {

			//if temp is lower than absolute zero in celsius sets temp to absolute zero 
			if (temp<(-273.15)){
				this.temp=-273.15;
			
			//sets new temp from old temp
			}else{
				this.temp=temp;
			}

			//sets scale to celsius
			this.scale=Scale.CELSIUS;

		//check if the first letter capitalized is equal to C
		}else if (Character.toUpperCase(scale.charAt(0))=='F'){

			//if temp is lower than absolute zero in fahrenheit sets temp to absolute zero 
			if (temp<(-459.67)){
				this.temp=-459.67;

			//sets new temp from old temp
			}else{
				this.temp=temp;
			}

			//sets scale to fahrenheit
			this.scale=Scale.FAHRENHEIT;

		//this means the scale is kelvin
		}else{

			//if temp is lower than absolute zero in kelvin sets temp to absolute zero 
			if (temp<(0)){
				this.temp=0;
			
			//sets new temp from old temp
			}else{
				this.temp=temp;
			}

			//sets scale to kelvin
			this.scale=Scale.KELVIN;
		}
		return this;  // do NOT change this return statement.
	}













	/* ------------------------------------------------- */
	/* ------------------------------------------------- */
	/* do not change anything below this                 */
	/* ------------------------------------------------- */
	/* ------------------------------------------------- */

	/** String representation of a temperature object    */
	@Override
	public String toString(){
		return "" + this.getTemp() + this.getScale();
	}
}
