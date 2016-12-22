#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

class html
{
	public:
	char str[1000];
	ofstream outfile;
	html()
	{
		outfile.open("index.html");
		strcpy(str,"");
	}
	void htmltagopen()
	{
		strcpy(str,"<!DOCTYPE html>\n<html>\n");
		outfile<<str;
	}
	void setup()
	{
		strcpy(str,"\n<head>\n<title>");
		cout<<"\n\tPlease enter the title Of your Webpage!!\n";
		outfile<<str;
		cin.getline(str,sizeof(str));
		outfile<<str;
	
		strcpy(str,"</title>\n");
		outfile<<str;		

		strcpy(str,"\n<link rel=\"stylesheet\" type=\"text/css\" href=\"theme.css\">\n");
		outfile<<str;

		strcpy(str,"</head>\n");
		outfile<<str;		
	}
	void marquee()
	{
		int j;
		strcpy(str,"\n<marquee ");
		outfile<<str;
		
		cout<<"\n\tSpecification Of The Design:\t";
		cout<<"Behaviour=>\n1.Normal\n2.Alternate\n";
		cout<<"\nNOTE: Only use integers \n\n";
		cin>>j;

		switch(j)
		{
			case 1:
			break;
			case 2:
			{
				strcpy(str," behavior = alternate ");
				outfile<<str;
				break;
			}
		}
		

		strcpy(str," >");
                outfile<<str;

		cout<<"\n\tEnter The Text For The Sliding Effect:\t";
		
		cin.clear();
                cin.getline(str,sizeof(str));
                cin.clear();
                cin.getline(str,sizeof(str));		

		outfile<<str;

		strcpy(str,"</marquee>\n");
                outfile<<str;
	}
	void object()
	{
		strcpy(str,"\n<div class=");
		outfile<<str;	
		char obj[25];
		cout<<"\n\tEnter div tag Class Name:\t";
		cin>>obj;	
		outfile<<obj;
		strcpy(str,">\n");
		outfile<<str;
		int i;
		char c;
		q:
		cout<<"\n\tWhat do you want to enter in the Body!";
		cout<<"\n1. Heading\n2. Para\n3. Marquee\n4. Link\n5. List\n6. Adding Images\n7. Adding Videos\n8. EXIT\n";
		cout<<"\nNOTE: Only use integers!! \n";
		cin>>i;
		switch(i)
		{
			case 1:
			{
				strcpy(str,"\n<h1>");
				outfile<<str;				
		
				cout<<"\n\tDo you want to Center allign the text! Press (Y/y):\t";
				cin>>c;
				if(c=='Y'||c=='y')
				{	
					strcpy(str,"\n<center>");
					outfile<<str;

				}

				cout<<"\n\tEnter the Heading:\t";
								
				cin.clear();
				cin.getline(str,sizeof(str));
				cin.clear();
				cin.getline(str,sizeof(str));
				
				outfile<<str;


				if(c=='Y'||c=='y')
                                {
                                        strcpy(str,"</center>\n");
					outfile<<str;

                                }

				strcpy(str,"</h1>\n");
				outfile<<str;
				//goto q;	
				break;
			}
			case 2:
			{
				strcpy(str,"\n<p>");     
                                outfile<<str;
                                cout<<"\n\tEnter the Paragraph:\t";               
                                
				cin.clear();
				cin.getline(str,sizeof(str));
				cin.clear();
                                cin.getline(str,sizeof(str));

                                outfile<<str;
                                strcpy(str,"</p>\n");
                                outfile<<str;
				//goto q;
				break;
			}
			case 3:
			{
				marquee();
				break;
			}
			case 4:
			{
				strcpy(str,"\n<a href=\"");
				outfile<<str;
				cout<<"\n\tEnter the link:\t";
				cin>>str;
				outfile<<str<<"\">";
				cout<<"\n\tEnter the name of the link:\t";
				cin.clear();
				cin.getline(str,sizeof(str));
				cin.clear();
                cin.getline(str,sizeof(str));
				outfile<<str<<"</a>";
				break;
			}
			case 5:
			{
				strcpy(str,"\n<ul>\n<li>");
				outfile<<str;
				cout<<"\n\tEnter the list element:\t";
				cin.clear();
				cin.getline(str,sizeof(str));
				cin.clear();
				cin.getline(str,sizeof(str));
				outfile<<str<<"</li>\n</ul>";
				break;
			}
			case 6:
			{
				strcpy(str,"<div class=\"sidebar\">\n<img src=\"");
				outfile<<str;
				cout<<"\n\tEnter the image with its location:\t";
				cin>>str;
				outfile<<str<<"\" width=\"900\" height=\"360\">\n</div>";
				break;
			}
			case 7:
			{
				strcpy(str,"\n<div class=\"sidebar\">\n<video width=\"900\" height=\"360\" controls>\n<source src=\"");
				outfile<<str;
				cout<<"\n\tEnter the video with its location:\t";
				cin>>str;
				outfile<<str<<"\" typr=\"video/";
				cout<<"\n\tEnter the format:\t";
				cin>>str;
				outfile<<str<<"\">\nYour browser doesn't support the format\n</video>\n</div>";
				break;
			}
			case 8:
			{
				goto app;
				break;
			}
			default:
			{
				break;
			}
		/*	default:
			{
				int j;
				cout<<"\n\tYou haven't entered anything in the body\n\tIf do not want to try again! Press 0 to leave:\t";
				cin>>j;
				if(j!=0)
				{
					goto q;
				}
			}	
		*/	
		}
		cout<<"\n\tNOTE: Only use integers!! \n";
		cout<<"\n\tIf you want to enter more! Press 1\t";
		int j;
		cin>>j;
		if(j==1)
		{
			goto q;
		}
		app:
		strcpy(str,"\n</div>\n");
                outfile<<str;
	}
	void body()
        {
                char l;
		strcpy(str,"\n<body>\n<script src=\"jsp.jsp\"></script>\n");
                outfile<<str;
                
		do
		{
			object();
			cout<<"\n\tTo create another class object. Press (Y/y)\t";
			cin.clear();
			cin>>l;
		}
		while(l=='y');
		strcpy(str,"\n</body>\n");
                outfile<<str;
        }
	void htmltagclose()
        {
                strcpy(str,"\n</html>");
                outfile<<str;
        }

        ~html()
        {
        	outfile.close();
        }

};

class css
{
	public:
	char ctr[1000];
	ofstream out;
	css()
	{
		out.open("theme.css");
		strcpy(ctr,"");
	}
	void csshead()
	{
		strcpy(ctr,"head{");
		out<<ctr;
		strcpy(ctr,"\nheight:100%;\nwidth:100%;\nmargin:0;\npadding:0;\n}");
		out<<ctr;
	}
	void cssbody()
	{
		strcpy(ctr,"\nbody{\nmargin: 0;\npadding: 0;\nfont-size: 90%;\ncolor: #000;\nbackground-color: #cccccc;\nbackground-size: cover;\nbackground-repeat: no-repeat;\nbackground-position: center;");
		out<<ctr;
		cout<<"\nSelect Background Type:\n1.Linear Gradient\n2.Radial Gradient(Only Red, Yellow & Green)\n3.Add Image\n";
		cout<<"\nNOTE: Only use integers!! \n";
		int k;
		cin>>k;
		switch(k)
		{
		case 1:
			char type[10];
			cout<<"\n\tSpecify the design direction/degree:\t";
			cin>>type;
			cout<<"\n\tEnter 2 colours of your choice for the background:\t";
			char one[10],two[10];
			cin>>one>>two;
			strcpy(ctr,"\nbackground: -webkit-linear-gradient(");
			out<<ctr;
			out<<type<<",";
			out<<one<<","<<two;
			out<<");";
			strcpy(ctr,"\nbackground: -moz-linear-gradient(");
			out<<ctr;
			out<<type<<",";
			out<<one<<","<<two;
			out<<");";	
			strcpy(ctr,"\nbackground: -ms-linear-gradient(");
			out<<ctr;
			out<<type<<",";
			out<<one<<","<<two;
			out<<");";	
			strcpy(ctr,"\nbackground: -o-linear-gradient(");
			out<<ctr;
			out<<type<<",";
			out<<one<<","<<two;
			out<<");";	
			strcpy(ctr,"\nbackground: linear-gradient(");
			out<<ctr;
			out<<type<<",";
			out<<one<<","<<two;
			out<<");";					
			break;
		case 2:
			strcpy(ctr,"background: -webkit-repeating-radial-gradient(red, yellow 10%, green 15%);\nbackground: -o-repeating-radial-gradient(red, yellow 10%, green 15%);\nbackground: -moz-repeating-radial-gradient(red, yellow 10%, green 15%);\nbackground: repeating-radial-gradient(red, yellow 10%, green 15%);");
			out<<ctr;
			break;	
		case 3:
			strcpy(ctr,"\nbackground-image: url(\"");
			out<<ctr;
			cout<<"\n\tEnter the image with its location:\t";
			cin>>ctr;
			out<<ctr<<"\");";	
			break;
		}
		strcpy(ctr,"\n}");
		out<<ctr;	
	}
	void cssh1()
	{
		strcpy(ctr,"\nh1{\nfont-family:\"Comic Sans MS\", cursive, sans-serif;");
		out<<ctr;
		cout<<"\n\tPress (Y/y) for small caps font varient:\t";
		char d;
		cin>>d;
		if(d=='Y'||d=='y')
		{
			strcpy(ctr,"\nfont-variant: small-caps;");
			out<<ctr;
		}
		cout<<"\n\tPress (Y/y) for padding:\t";
		cin>>d;
		if(d=='Y'||d=='y')
		{
			strcpy(ctr,"\npadding: 20px;");
			out<<ctr;
			strcpy(ctr,"\nbackground-color:");
			out<<ctr;
			cout<<"\n\tSpecify padding colour:\t";
			cin>>ctr;
			out<<ctr;
			strcpy(ctr,";");
			out<<ctr;
		}
		strcpy(ctr,"color:");
		out<<ctr;
		cout<<"\n\tSpecify the colour of your Heading:\t";
		cin>>ctr;
		out<<ctr;
		strcpy(ctr,";\n}");
		out<<ctr;
	}
	void cssp()
	{
		strcpy(ctr,"\np{color:");
		out<<ctr;
		cout<<"\n\tEnter the colour of the para:\t";
		cin>>ctr;
		out<<ctr<<";";
		cout<<"\n\tDo you want padding for the para (Y/y):\t";
		char c;
		cin>>c;
		if (c=='Y'||c=='y')
		{
			strcpy(ctr,"\npadding:10px;");
			cout<<"\n\tSpecify Padding colour:\t";
			strcpy(ctr,"\nbackground-color:");
			out<<ctr;
			cin>>ctr;
			out<<ctr<<";";
		}
		cout<<"\n\tDo you want to add a border (Y/y):\t";
		cin>>c;
		if (c=='Y'||c=='y')
		{
			cout<<"\n\tBorder Property: Inset and 5px by default"<<endl;
			strcpy(ctr,"\nborder-style: inset;\nborder-width: 5px;");
			out<<ctr;
		}
		out<<"\n}";
	}
	void cssli()
	{
		strcpy(ctr,"\nul{\nlist-style-type: square;\n}");
		out<<ctr;
	}
	void cssobject()
	{
		char c;
		cout<<"\n\tYou can use a div class to further edit the webpage. Press (Y/y):\t";
		cin>>c;
		if(c=='Y'||c=='y')
		{
			cin.clear();
			cin.getline(ctr,sizeof(ctr));
			cin.clear();
			cin.getline(ctr,sizeof(ctr));
			out<<endl<<ctr<<endl;
		} 
	}
	void cssa()
	{
		strcpy(ctr,"\na{\ntext-decoration: none;\n}");
		out<<ctr;
		char c;
		cout<<"\n\tDo you want hover effect for the link (Y/y):\t";
		cin>>c;
		if(c=='Y'||c=='y')
		{
			strcpy(ctr,"\na:hover{\ncolor: black;\nbackground-color: white;\n}");
			out<<ctr;
		}
	}
	void cssimg()
	{
		strcpy(ctr,".sidebar{ \nbackground: -webkit-linear-gradient(90deg, #ED4264 10%, #FFEDBC 90%); /* Chrome 10+, Saf5.1+ */\nbackground:    -moz-linear-gradient(90deg, #ED4264 10%, #FFEDBC 90%); /* FF3.6+ */\nbackground:     -ms-linear-gradient(90deg, #ED4264 10%, #FFEDBC 90%); /* IE10 */\nbackground:      -o-linear-gradient(90deg, #ED4264 10%, #FFEDBC 90%); /* Opera 11.10+ */\nbackground:         linear-gradient(90deg, #ED4264 10%, #FFEDBC 90%); /* W3C */        \nborder-radius: 5px;\npadding: 20px;\nfont-size: 110%;\nmargin-top: 20px;\nmargin-bottom: 10px;\nmargin-left: 10px;\nmargin-right: 10px;\nfloat: left;\nwidth: 900px;\nclear: left;\n}");
		out<<ctr;
	}
	void cssmarquee()
	{
		strcpy(ctr,"\nmarquee{\nfont-style: italic;\n}");
		out<<ctr;
	}

	~css()
	{
		out.close();
	}
};

int main()
{
	system("clear");
	cout<<"===============================================================================";
	cout<<"\n=========================Web Development Kit v1.0=============================";
	cout<<"\n===============================================================================";
	cout<<"\nHTML Editing Mode Activated"<<endl;
	html Page;
	Page.htmltagopen();
	Page.setup();
	Page.body();
	Page.htmltagclose();
	cout<<"\nCSS Editing Mode Activated"<<endl;
	css Style;
	Style.csshead();
	Style.cssbody();
	int n;
	do{
	cout<<"\nPress Appropriate Number For Editting:\n1. Heading\n2. Para\n3. Marquee\n4. Link\n5. Unordered List\n6. Image\n7. Video\n8. EXIT\n";
	cout<<"\nNOTE: Only use integers!! \n";
	cin>>n;
	switch(n)
	{
	case 1:
		Style.cssh1();
		break;
	case 2:
		Style.cssp();
		break;
	case 3:
		Style.cssmarquee();
		break;
	case 4:	
		Style.cssa();
		break;
	case 5:
		Style.cssli();
		break;
	case 6:
		Style.cssimg();
		break;
	case 7:
		Style.cssimg();
		break;
	case 8:
		goto x;
		break;	
	default:
		break;	
	}	
	cout<<"\nNOTE: Only use integers!! \n";
	cout<<"\nTo edit more! Press 1\t";
	cin>>n;
	}while(n==1);
	h:
	x:
	cout<<"\nDo you want to edit the div class (Y/y):\t";
	char z;
	cin>>z;
	if(z=='Y'||z=='y')
	{
		cout<<"\n\tNOTE:Don't press \'ENTER\' until you have entered the design!!"<<endl;
		Style.cssobject();
		goto h;
	}


	ofstream jspout("script.jsp");
	jspout<<"\nvar name = prompt(\"What's Your Name?\");";
	jspout<<"\nvar str = \"Welcome \"+name;";
	jspout<<"\ndocument.write(\"<h2><b><center>\"+str+\"</center></b></h2>\");";
	jspout<<"\ndocument.write(\"<style type=text/css>h2{text-transform: uppercase;}</style>\");";
	jspout.close();

	int listenfd = 0;
    int connfd = 0;
    struct sockaddr_in serv_addr;
    char sendBuff[1025];
    int numrv;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    printf("\nSocket retrieve success\n");

    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5001);

    bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

    if(listen(listenfd, 10) == -1)
    {
        printf("\nFailed to listen\n");
        return -1;
    }


    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);

        FILE *fp = fopen("script.jsp","rb");
        if(fp==NULL)
        {
            printf("\nFile opern error\n");
            return 1;   
        }   

        while(1)
        {
            unsigned char buff[256]={0};
            int nread = fread(buff,1,256,fp);
            printf("\nBytes read %d \n", nread);        

            if(nread > 0)
            {
                printf("Sending \n");
                write(connfd, buff, nread);
            }

            if (nread < 256)
            {
                if (feof(fp))
                    printf("\nEnd of file\n");
                	goto n;
                if (ferror(fp))
                    printf("\nError reading\n");
                	goto n;
                break;
            }

        }
        
        close(connfd);
        sleep(1);
    }
	n:

	return 0;
}
