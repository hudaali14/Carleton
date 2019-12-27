double average=0.00;
		int num=0;
		WeatherReport[] reports=new WeatherReport[10];
		for(int x=0; x<weatherStations.length; x++){
			if (weatherStations[x]!=null){
				reports=weatherStations[x].getReports();
				for (int w=0; w<reports.length; w++){
					if (reports[w]!=null){
						if (reports[w].getTime().getDay()>=startDay && reports[w].getTime().getDay()<=endDay){
							average+=reports[w].getTemperature().setScale(Scale.CELSIUS).getTemp();
							num+=1;
						}
					}
				}
			}
		}
		if (average!=0){
			average= average/num;
		}
        return average;
        

        Temperature highest=null;
		WeatherReport reports=null;
		for (int k=0; k<this.weatherStations.length; k++){
			reports=this.weatherStations[k].getReports();
			for (int g=0; g<reports.length; g++){
				if (reports[g].getTime().getDay()==day){
					if ()
				}
			}
        }
        
        Temperature highest=null;
		WeatherReport[] reports=null;
		for (int k=0; k<this.weatherStations.length; k++){
			reports=this.weatherStations[k].getReports();
			for (int g=0; g<reports.length; g++){
				if (reports[g].getTime().getDay()==day){
					if (Compare.compare(reports[g].getTemperature(), highest)==1){
						highest=reports[g].getTemperature();
					}
				}
			}
		}

        Temperature highest= new Temperature(0.00);
		WeatherReport[] reports=new WeatherReport[10];
		for(int h=0; h<weatherStations.length; h++){
			if (weatherStations[h]!=null){
				reports=weatherStations[h].getReports();
				for (int g=0; g<reports.length; g++){
					if (reports[g]!=null && reports[g].temperature!=null){
						if (day==reports[g].getTime().getDay()){
							if(Compare.compare(reports[g].temperature,highest)==1){
								highest=reports[g].temperature;
							}
						}
					}
				}
			}
		}
        return highest;


        Temperature highest= new Temperature(0.00);
		for(int k=0; k<weatherStations.length; k++){
			if (weatherStations[k]!=null && weatherStations[k].getReportWithMaxTemp()!=null){
				if (Compare.compare(weatherStations[k].getReportWithMaxTemp().temperature, highest)==1){
					highest=weatherStations[k].getReportWithMaxTemp().temperature;
				}
			}
		}
		return highest;