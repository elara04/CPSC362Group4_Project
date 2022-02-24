#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int check_in_list(std::string & check_str /*,int position_in_vector*/) // this function will check if string is in list text file
{std::ifstream readfile("menu masters.txt");
if(readfile.is_open())
{  int i =0;
  std::string line;

  while( std::getline(readfile >> std::ws, line))
  {i++;
    size_t pos = line.find(check_str);
    if ( pos != std::string::npos)
     { std::cout << "entry " << check_str <<" is in the list on line " << i << " and will not be added" << std::endl;
        return i-1;
        
        
     }
     else
     {
     continue;
     
     //std::cout << "added new entry to the list\n"; 
     }
  }
  std::cout << "entry " << check_str << " was not in the list" << " and will now be added \n\n";
    readfile.close();
    
}
return -2;
}
 

int main()
{
    std::cout << "enter the number of entries you will be making: ";
    int num_of_entries;
   std::cin >> num_of_entries;
      
    printf("\n");
    std::vector<std::string>  name_of_place;
    for(int i = 0; i < num_of_entries; i++)
    {
        std::string temp_str;
        std::cout <<"enter the name of the place:";
        std::getline(std::cin >> std::ws, temp_str); 
        name_of_place.push_back(temp_str);
        std::cout << "\n";
    }



for(std::string name : name_of_place)
{int position;
    position = check_in_list(name);
    if(position < -1)
    {continue;}
    else if(position == -1)
    {name_of_place.erase(name_of_place.begin());
    }
    else
    {name_of_place.erase(name_of_place.begin()+position);}
}


{

std::ofstream writefile;
writefile.open("menu masters.txt",std::ios::app);
if(writefile.is_open())
{
    for(std::string input_str  : name_of_place)
    writefile << input_str << "\n";
}
  
writefile.close();
}

//std::string driver_str{"test"};
//check_in_list(driver_str);

return 0;
}
