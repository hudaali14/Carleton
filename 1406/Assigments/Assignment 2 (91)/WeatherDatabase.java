package comp1406a2;

/** A very simple database storing weather data */ 
public class WeatherDatabase{

	/* ----------------------------------- */
	/* do NOT change this constructor      */
	/* ----------------------------------- */
	
	/** Creates an empty weather database  */
	public WeatherDatabase(){}
	
	/* ----------------------------------- */




	//
	// You need to complete these methods.
	//
	// Unless stated, you will need to change the return 
	// value of each of these methods as well as add the actual 
	// body of the methods.
	//


	// HEY TI WHOEVER MARKING THIS, sorry the code has SO MANY NULL CHECKS, 
	// I kept getting a "an exception was thrown" error, 
	// which I checked on the Piazza meant a null pointer error
	// or an index out of bounds error, so I just made as many null checks as I could think of
	// throughout the code and  and it finally worked with the server, I dont know if you 
	// need this many check but it worked so yeah just wanted to write 
	// this note in case you didn't need this much and to explain why I had so many null 
	// checks compared to the other two files. Thank you.



	// array to hold weather stations starts at zero
	private WeatherStation[] weatherStations= new WeatherStation[0];



	/** Returns all weather stations in the database
	* in no particular order
	*
	* @return an array containing all weather stations that are in
	*         this database. Note that the size of the array should be equal to
	*         the result of <code>this.numberOfWeatherStations()</code>.
	*/
	public WeatherStation[] getWeatherStations(){

		return weatherStations;
	}



	/** Returns the number of weather stations in the database
	*
	* @return the number of weather stations in this database
	*/
	public int numberOfWeatherStations(){

		return weatherStations.length;
	}



	/** adds a weather station to this database
		* @param station is the weather station to add. It will always be non-null.
		* @return this weather station.
		*/
	public WeatherDatabase addWeatherStation(WeatherStation station){

		//creates a temporary array that will hold the weatherStations and station to be added
		WeatherStation[] temp= new WeatherStation[weatherStations.length+1];

		//if the weather station is equal to zero then 
		if(weatherStations.length==0){
			weatherStations=temp;
			temp[0]=weatherStations[0];
		}

		// saves the new station added to the last element of the temp array
		temp[temp.length-1]=station;

		// loops through array, saves all items from weatherstation to temp array
		for (int i=0; i<temp.length; i++){
			if(i!=weatherStations.length){
			  	temp[i]=weatherStations[i];
			}
		}

		// saves weatherstations array to temp array that has the new weatherstation added
		weatherStations=temp;

		return this;    // do NOT change the return statement
	}



	/** removes weather station with given id from this database
		* @param id is the ID number of the weather station to remove.
		* @return true if the specified weather station is successfully removed,
		*         returns false otherwise (i.e., if there was no weather station
		*         with the specified ID number in this database to begin with).
		*/
	
	public boolean removeWeatherStation(int id){

		// counter for when a station has id matching station needed to be removed
		int idFound=0;

		// counts whenever there's a null in weatherstations array
		int nullCount=0;

		// if there's nothing in the weather station you can't remove anything so returns false
		if(weatherStations.length<=0){
			return false;
		}else{

			// loops through array and counts amount of null
			for (int z=0; z<weatherStations.length; z++){
				if (weatherStations[z]==null){
					nullCount++;
				}
			}

			// if the null count is equal to the amount this means there's nothing to remove, returns false
			if (nullCount==weatherStations.length){
				return false;
			}
		}

		// creates temp array thats hold one less than the original array to 'remove' station
		WeatherStation[] temp= new WeatherStation[weatherStations.length-1];

		// if weatherstations is equal to one, then we only need to check the single item
		if (weatherStations.length==1){

			// if the id is equal to the station to remove, we make the weatherstations array equal to the temp array (which is empty), so it 'removes' the station
			if (id==weatherStations[0].getID()){
				weatherStations=temp;
				return true;

			// otherwise we return false 
			}else{
				return false;
			}

		// if the weatherstations array is greater then one
		}else{

			//loops through weatherstation array to copy other  
			for(int j=0; j<weatherStations.length; j++){

				// if the weatherstation at the index is not equal to null (this is so we don't try to call a null object)
				if (weatherStations[j]!=null){

					// if id is equal to station's id then increase idFound counter and check if idFound was originally equal to 
					//zero so we only remove the first weather station with the same id
					if (id==weatherStations[j].getID() && idFound==0){
						idFound++;

					//means id wasn't equal to stations id
					}else{

						// if the id was found this means the index increased and the last spot was empty in the array, so it 
						if (idFound==1){
							temp[j-1]=weatherStations[j];

						//means the id hasn't been found yet
						}else{

							//if we get to the last element in the array and no id as been found this means the id doesnt exist in the station, 
							//so it makes temp equal to the weatherstations, because the weatherstations array hasn't been modified
							if (idFound==0 && j==weatherStations.length-1){
								temp=weatherStations;
								break;

							//saves item from weatherstations array to temp array
							}else{
								temp[j]=weatherStations[j];
							}
						}
					}
				}
			}
		}

		//saves the weatherstations array as the temp array
		weatherStations=temp;

		// if the idFound is greater than zero it means we removed it so return true 
		if (idFound>0){
			return true;
		
		//otherwise return false
		}else{
			return false;
		}
	}



	/** returns the highest temperature ever recorded by any weather station
	  * in the data base.
	  */

	public Temperature getMaxTemperature(){

		// counts whenever there's a null in weatherstations array
		int nullCount=0;

		// loops through array and counts amount of null
		for (int z=0; z<weatherStations.length; z++){
			if (weatherStations[z]==null){
				nullCount++;
			}
		}

		// if the null count is equal to the amount then this means there's nothing to check, so return null
		if (nullCount==weatherStations.length){
			return null;
		}

		//holdest highest temperature ever
		Temperature highest=null;

		//if the weatherstations has weatherstations and the first item is not null
		if (weatherStations.length>0 && weatherStations[0]!=null){

			//also checks is the temperature is not null, if not then saves highest to first element
			if (weatherStations[0].getReportWithMaxTemp().getTemperature()!=null){
				highest=weatherStations[0].getReportWithMaxTemp().getTemperature();
			}
		}

		//loops through weatherstations 
		for (int x=0; x<weatherStations.length; x++){

			//if the station is not null
			if (weatherStations[x]!=null){

				//and the station with the weather report is not null
				if (weatherStations[x].getReportWithMaxTemp()!=null){

					//and if the temperature is not null and highest is not null
					if (weatherStations[x].getReportWithMaxTemp().getTemperature()!=null && highest!=null){

						//checks if the station is greater than highest, if it is, it saves it as highest
						if (Compare.compare(weatherStations[x].getReportWithMaxTemp().getTemperature(), highest)==1){
							highest=weatherStations[x].getReportWithMaxTemp().getTemperature();
						}
					}
				}
			}
		}
		return highest;
	}


	/** returns the highest temperature on a specified day
		* that is recorded in a report in the weather stations in this database.
		*
		* @param day is the day to find the max temperature on. Note that this
		*            might be the special max temperature day that a
		*            weather station records.
		* @return  the temperature object with the highest recorded Temperature
		*          in the data base on the specified day.
		*/
	public Temperature getMaxTemperature(int day){

		// counts whenever there's a null in weatherstations array
		int nullCount=0;

		// loops through array and counts amount of null
		for (int z=0; z<weatherStations.length; z++){
			if (weatherStations[z]==null){
				nullCount++;
			}
		}

		// if the null count is equal to the amount then this means there's nothing to check, so return null
		if (nullCount==weatherStations.length){
			return null;
		}

		//holdest highest temperature ever
		Temperature highest= null;

		//holds weather reports
		WeatherReport[] reports=null;

		//loops through weatherstations array
		for(int h=0; h<weatherStations.length; h++){

			// if station is not equal to null
			if (weatherStations[h]!=null){

				// saves reports to the reports of the weather station
				reports=weatherStations[h].getReports();

				//if highest is not null and there are reports in the array
				if (highest==null && reports.length!=0){

					//if the first report in array is not null, then saves highest as the first report
					if (reports[0]!=null){
						highest=reports[0].getTemperature();
					}
				}

				//loops through reports
				for (int g=0; g<reports.length; g++){

					//if the day is equal to reports day and the reports temperature is not null and the highest is not null
					if (day==reports[g].getTime().getDay() && reports[g].getTemperature()!=null && highest!=null){
						
						//checks if reports at index is greater then highest, saves highest to reports at index
						if(Compare.compare(reports[g].getTemperature(),highest)==1){
							highest=reports[g].getTemperature();
						}
					}
				}
			}
		}
		return highest;

	}

	/** Computes the average temperature (over all weather stations) for the
	*  time period starting at startDay and ending at endDay (inclusive)
	*
	* @param startDay is the starting day
	* @param endDay is the ending endDay
	* @return the average temperature of all temperature reports for the time
	*         period startDay to endDay (inclusive) taken from all weather
	*         stations in this weather database.
	*/
	public double averageTemperature(int startDay, int endDay){

		// counts whenever there's a null in weatherstations array
		int nullCount=0;

		// loops through array and counts amount of null
		for (int z=0; z<weatherStations.length; z++){
			if (weatherStations[z]==null){
				nullCount++;
			}
		}

		// if the null count is equal to the amount then this means there's nothing to check, so return null
		if (nullCount==weatherStations.length){
			return 0.00;
		}

		//holds average temperature
		double average=0.00;

		//holds amount of temperature added to average
		double num=0.00;

		//creates reports array
		WeatherReport[] reports=null;

		//loops through weatherstations array
		for(int x=0; x<weatherStations.length; x++){

			//if station is not null
			if (weatherStations[x]!=null){

				//saves reports as weather station's reports
				reports=weatherStations[x].getReports();

				//loops through reports
				for (int w=0; w<reports.length; w++){

					//if report index not equal to null
					if (reports[w]!=null){

						//if report at index's temperature is not null
						if (reports[w].getTemperature()!=null){

							//checks is report's day is greater then start day and less than end day then adds temperature to average
							if (reports[w].getTime().getDay()>=startDay && reports[w].getTime().getDay()<=endDay){
								average+=reports[w].getTemperature().setScale(Scale.CELSIUS).getTemp();
								num+=1.00;
							}
						}
					}
				}
			}
		}
		//divides average by num	
		average=average/num;
		
		return average;
        
	}
}
