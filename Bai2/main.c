/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-04-26 16:06:52
 * @modify date 2023-05-09
 * @desc [Reverse words and number of repetitions of words in sequence]
 */



/*Word data type definition*/

typedef struct {
    char word[50];
    int length;
} Word;


/*
* Function: stringCompare
* Description: Compares two strings of characters and returns 1 if the two strings are the same, otherwise returns 0.
* Example:
* Input:
*   str1 = "hello"
*   str2 = "hello"
* Output:
*   return: 1 
*/

int stringCompare(char *str1, char *str2) {
    int i = 0; 
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            //KIỂM TRA TỪNG CẶP KÝ TỰ TẠI VỊ TRÍ "i" TRONG str1 VÀ  str2 
            //NẾU CÓ SỰ KHÁC BIỆT. TỨC HAI CHUỖI KHÁC NHAU -> HÀM TRẢ VỀ 0 
            return 0;
        }
        i++; //TĂNG BIẾN ĐẾM "i" ĐỂ CHUYỂN SANG KÝ THỰ TIẾP THEO
    }

    //KIỂM TRA NẾU ĐẾN CUỐI CÙNG CỦA HAI CHUỖI. 
    //NẾU GIỐNG NHAU ( return 1). 
    //NẾU MỘT TRONG HAI CHUỖI ĐÃ KẾT THÚC(KHÁC NHAU VỀ ĐỘ DÀI) (return 0)
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}


/*
* Function: reverseWords
* Description: The reverseWords function to reverse the words in the input string and count the number of occurrences of each word.
*/

void reverseWords(char *str, Word *words) {
    int i = 0, j = 0, k = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {            //KIỂM TRA XEM KÝ TỰ HIỆN TẠI CÓ PHẢI KHOẢNG TRẮNG HAY KHÔNG
            words[j].word[k] = '\0';    //ĐẶT KÝ TỰ KẾT THÚC CHUỖI "\0" VÀO CUỐI TỪ HIỆN TẠI
            words[j].length = k;        //LƯU ĐỘ DÀI HIỆN TẠI VÀO TRƯỜNG lenght
            k = 0;                      //RESET k  ĐỂ BẮT ĐẦU ĐỌC TỪ MỚI
            j++;                        //CHUYỂN SANG TỪ MỚI TRONG MẢNG WORDS
        } else {
            words[j].word[k++] = str[i];//NẾU KÝ TỰ HIỆN TẠI KHÔNG PHẢI LÀ KHOẢNG TRẮNG. LƯU KÝ TỰ VÀO TỪ HIỆN TẠI VÀ TĂNG BIẾN ĐẾM k
        }
        i++;
    }
    words[j].word[k] = '\0';            //ĐẶT KÝ TỰ KẾT THÚC CHUỖI '\0' VÀO CUỐI TỪ HIỆN TẠI
    words[j].length = k;                //LƯU ĐỘ DÀI CỦA TỪ HIỆN TỊA VÀO TRƯỜNG length
    int n = j;                          //SỐ LƯỢNG TỪ ĐÃ ĐỌC ĐƯỢC TRONG CHUỖI

    /*IN CÁC TỪ ĐÃ ĐỌC ĐƯỢC NGƯỢC LẠI TỪ CUỐI CHUỖI ĐẾN ĐẦU CHUỐI*/
    for (j = n; j >= 0; j--) {
        printf("%s ", words[j].word);
    }

    /*ĐẾM SỐ LẦN XUẤT HIỆN TRONG CHUỖI VÀ IN KẾT QUẢ*/
    for (j = 0; j <= n; j++) {
        int count = 1;                  //KHỞI TẠO BIẾN COUNT ĐỂ ĐẾM SỐ LẦN XUẤT HIỆN CỦA TỪ
        for (k = j + 1; k <= n; k++) {
            if (stringCompare(words[j].word, words[k].word)) {//NẾU HÀM stringCompare TRẢ VỀ BẰNG 1 THÌ CÓ SỰ TRÙNG LẶP.
                count++;
                words[k].word[0] = '\0';//ĐÁNH DẤU TỪ ĐÃ ĐƯỢC ĐẾM BẰNG KÝ TỰ KẾT THÚC CHUỖI '\0'
            }
        }
        if (words[j].word[0] != '\0') {
            printf("\n%s: %d", words[j].word, count);
        }
    }

}



int main() {
    char str[] = "He wanted to do something fun. He wanted to do something fun with his friend. He called up his friend.";
    Word words[50];
    reverseWords(str, words);
    return 0;
}


