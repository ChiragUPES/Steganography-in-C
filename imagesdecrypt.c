#include<stdio.h>
#include<stdlib.h>

int get_offset(FILE* image_offset) {
        fseek(image_offset,10,0);
        int offset;
        offset=(int)fgetc(image_offset);
        return offset;
}

long binary(char ch){
        long num = ch;
        long remainder = 0,base = 1,binary=0;
        while(num > 0)
        {
                remainder = num % 2;
                binary = binary + remainder * base;
                num = num / 2;
                base = base * 10;
        }
        //printf("%ld\n",binary);
        return binary;
}

long reverse(long temp) {
        long lol=0;
        while(temp>0) {
                lol = lol * 10 + (temp % 10);
                temp = temp / 10;
        }
        return lol;
}


int power(int x, unsigned int y) {
        if( y == 0)
                return 1;
        else if (y%2 == 0)
                return power(x, y/2)*power(x, y/2);
        else
                return x*power(x, y/2)*power(x, y/2);
}

int decimal(long bin) {
        int num=0,temp;
        int i;
        for(i=0;i<8;i++) {
                temp = bin % 10;
                bin = bin / 10;
                num = num + (temp * power(2,i));
        }
        return num;
}

int get_len(long bin) {
        int i;
        while(bin>0) {
                i++;
                bin = bin/10;
        }
        return i;
}

int main() {
	
			FILE *image;
		        FILE *text_file;
        		int x,i;
			char input[20],output[20];
        		printf("Enter the input image : ");
			scanf("%s",&input);
			image = fopen(input,"r");
        		if( image == NULL ) {
                		printf("Image didn't open");
                		exit(1);
        		}
			printf("Enter the output file: ");
			scanf("%s",&output);
        		text_file = fopen(output,"w");
        		fgetc(image);
        		x = ftell(image);
        		int offset,cnt=0;
        		offset = get_offset(image);
        		fseek(image,offset,0);
        		int temp;
        		unsigned long image_bin,data=0,lol;
        		char ch,ch1;
			long len;
			int text_len=0;
			for(i=0;i<8;i++) {
				ch = fgetc(image);
				image_bin = binary(ch);
				temp = image_bin % 10;
				data = data * 10 + temp;
				if(temp == 0 && data == 0) {
                                        cnt++;
                                }
			}
			printf("%d/n",data);
			len = reverse(data);
			printf("%d",len);

			/*if(cnt !=0) {
                                len = len * power(10,cnt);
                        }
			printf("len :%ld",len);*/
			/*text_len = decimal(len);
			//printf("laaaaaal :%d",text_len);
			temp =0;
			data = 0;
			for(i=1;i<=(text_len*8)-8;i++) {
                		ch = fgetc(image);
                		image_bin = binary(ch);
                		temp = image_bin % 10;
                		data = data * 10 + temp;
                		if(temp == 0 && data == 0) {
                        		cnt++;
                		}
                		//printf("temp :%d\tdata:%ld\n",temp,data);
                		if(i%8 == 0) {
                		        //printf("cnt :%d\n",cnt);
                		        //printf("%ld\n",data);
                		        lol = reverse(data);
                	       		//printf("%ld\n",lol);
                	        	if(cnt !=0) {
                	        	        lol = lol * power(10,cnt);
                	        	}
                	        	//printf("%ld\n",lol);
               		         	data = 0;
                	        	ch1 = (char)decimal(lol);
                	        	//printf("%c\n\n",ch1);
                	        	fputc(ch1,text_file);
                	        	cnt = 0;
                		}
                		//printf("%ld",data);
        		}*/
}

