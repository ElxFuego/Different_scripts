# About this program

It's one of the first programs I made- apart from calculators and other simple scripts of course. It's purpouse is to copy certain files from certain source directories, to particular target locations. I used it to update custom scripts in Cadmatic, as unfortunately, it didn't support any more sophisticated method.

You can see it wasn't made by pro dev, just by looking at use of "using namespace std" (which I read later is considered a bad practice). It can be also unnecessarily complex, but it was my first program in C++ which actually was useful :D 

I also used it to learn, so it was gradually changing- I have added classes instead of functions, used external files, vectors etc.

# How it works

It simply requires fnames.txt file in which you put your file name and target directory, seperated by ";". Its syntax is:

FILENAME1 ; C:/DIR1/DIR2
FILENAME2 ; D:/DIR2/DIR2

Originally I had files and its target directory in excell file, so it was easy to generate .csv from it. You can also create via program "SettingsFile" which will store source directory of files as well as directory of fnames.txt



