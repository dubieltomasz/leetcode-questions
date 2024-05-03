class Solution {
public:
    int compareVersion(const string& version1, const string& version2) {
        ushort i1 = 0, i2 = 0, n1 = version1.size(), n2 = version2.size();
        int32_t revision1 = 0, revision2 = 0;

        while(i1 < n1 && i2 < n2)
        {
            revision1 = 0;
            revision2 = 0;

            while(i1 < n1 && version1[i1] != '.')
            {
                revision1 *= 10;
                revision1 += int(version1[i1++])-48;
            }

            while(i2 < n2 && version2[i2] != '.')
            {
                revision2 *= 10;
                revision2 += int(version2[i2++])-48;
            }

            if(revision1 < revision2) return -1;
            else if(revision1 > revision2) return 1;

            ++i1;
            ++i2;
        }
        
        while(i1 < n1)
        {
            revision1 = 0;

            while(i1 < n1 && version1[i1] != '.')
            {
                revision1 *= 10;
                revision1 += int(version1[i1++])-48;
            }

            ++i1;
        
            if(revision1 > 0) return 1;
        }

        while(i2 < n2)
        {
            revision2 = 0;

            while(i2 < n2 && version2[i2] != '.')
            {
                revision2 *= 10;
                revision2 += int(version2[i2++])-48;
            }

            ++i2;
        
            if(revision2 > 0) return -1;
        }

        return 0;
    }
};
