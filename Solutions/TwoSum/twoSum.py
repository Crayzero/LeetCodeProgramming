class Solution:
    def twoSum(self, num, target):
        self.num2=[i for i in num]
        self.num=num
        self.num.sort()
        print num
        for i in num:
            if target-i>=0 and self.find(target-i)>0:
                index1=self.num2.index(i)+1
                if not i==target-i:
                    index2=self.num2.index(target-i)+1
                else:
                    print index1+1
                    index2=self.num2.index(target-i, index1)+1
                if index1>index2:
                    return (index2,index1)
                elif index1< index2:
                    return (index1, index2)

    def find(self,o):
        start=0;
        end=len(self.num)-1
        middle=(start+end)/2
        print o
        while(start <= end):
            print start,middle,end
            if self.num[middle]==o:
                return middle
            if self.num[middle]>o:
                end=middle-1
            if self.num[middle]<o:
                start=middle+1
            middle=(start+end)/2
        else:
            return -1

if __name__=='__main__':
    s=Solution()
    #print s.twoSum([591,955,829,805,312,83,764,841,12,744,104,773,627,306,731,539,349,811,662,341,465,300,491,423,569,405,508,802,500,747,689,506,129,325,918,606,918,370,623,905,321,670,879,607,140,543,997,530,356,446,444,184,787,199,614,685,778,929,819,612,737,344,471,645,726], 789)
    print s.twoSum([2,1,9,4,4,56,90,3],8)
