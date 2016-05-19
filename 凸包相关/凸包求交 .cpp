#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct POINTF {
    float x; float y;
};
//��֤���ȣ�����������֮��С��0.0001����Ϊ���
bool Equal(float f1, float f2) {
    return (abs(f1 - f2) < 1e-4f);
}
//�ж������Ƿ����
bool operator==(const POINTF &p1, const POINTF &p2) {
    return (Equal(p1.x, p2.x) && Equal(p1.y, p2.y));
}
//�Ƚ����������С���ȱȽ�x���꣬����ͬ��Ƚ�y����
bool operator>(const POINTF &p1, const POINTF &p2) {
    return (p1.x > p2.x || (Equal(p1.x, p2.x) && p1.y > p2.y));
}
//�������������
float operator^(const POINTF &p1, const POINTF &p2) {
    return (p1.x * p2.y - p1.y * p2.x);
}

//�ж����߶�λ�ù�ϵ�����������(�������)��
//���غϣ���ȫ�غ�(6)��1���˵��غ��ҹ���(5)�������غ�(4)
//���غϣ����˵��ཻ(3)����������(2)������(1)���޽�(0)����������(-1)
int Intersection(POINTF p1, POINTF p2, POINTF p3, POINTF p4, POINTF &Int) {
    //��֤����p1!=p2��p3!=p4
    if (p1 == p2 || p3 == p4) {
        return -1; //����-1����������һ���߶���β�غϣ����ܹ����߶�
    }
    //Ϊ�������㣬��֤���߶ε������ǰ���յ��ں�
    if (p1 > p2) {
        swap(p1, p2);
    }
    if (p3 > p4) {
        swap(p3, p4);
    }
    //������߶ι��ɵ�����
    POINTF v1 = {p2.x - p1.x, p2.y - p1.y}, v2 = {p4.x - p3.x, p4.y - p3.y};
    //�������������ƽ��ʱ���Ϊ0
    float Corss = v1 ^ v2;
    //�ж����߶��Ƿ���ȫ�غ�
    if (p1 == p3 && p2 == p4) {
        return 6;
    }
    //�������غ�
    if (p1 == p3) {
        Int = p1;
        //����غ��ҹ���(ƽ��)����5����ƽ�����ڶ˵㣬����3
        return (Equal(Corss, 0) ? 5 : 3);
    }
    //����յ��غ�
    if (p2 == p4) {
        Int = p2;
        //�յ��غ��ҹ���(ƽ��)����5����ƽ�����ڶ˵㣬����3
        return (Equal(Corss, 0) ? 5 : 3);
    }
    //������߶���β����
    if (p1 == p4) {
        Int = p1;
        return 3;
    }
    if (p2 == p3) {
        Int = p2;
        return 3;
    }//���������жϣ���β�����ص���������ų���
    //���߶ΰ���������������߶�1�����ϴ������߶ν���
    if (p1 > p3) {
        swap(p1, p3);
        swap(p2, p4);
        //����ԭ�ȼ���������������
        swap(v1, v2);
        Corss = v1 ^ v2;
    }
    //�������߶�ƽ�е����
    if (Equal(Corss, 0)) {
        //������v1(p1, p2)��vs(p1,p3)��������ж��Ƿ���
        POINTF vs = {p3.x - p1.x, p3.y - p1.y};
        //���Ϊ0����ƽ���߶ι��ߣ������ж��Ƿ����غϲ���
        if (Equal(v1 ^ vs, 0)) {
            //ǰһ���ߵ��յ���ں�һ���ߵ���㣬���ж������غ�
            if (p2 > p3) {
                Int = p3;
                return 4; //����ֵ4�����߶β����غ�
            }
        }//�����㲻���ߣ���������ƽ���߶αز����ߡ�
        //�����߻��ߵ����غϵ�ƽ���߾��޽���
        return 0;
    } //����Ϊ��ƽ�е�������Ƚ��п����ų�����
    //x���������򣬿�ֱ�ӱȽϡ�y����Ҫ�������߶ε�������Сֵ
    float ymax1 = p1.y, ymin1 = p2.y, ymax2 = p3.y, ymin2 = p4.y;
    if (ymax1 < ymin1) {
        swap(ymax1, ymin1);
    }
    if (ymax2 < ymin2) {
        swap(ymax2, ymin2);
    }
    //��������߶�Ϊ�Խ��ߵľ��β��ཻ�����޽���
    if (p1.x > p4.x || p2.x < p3.x || ymax1 < ymin2 || ymin1 > ymax2) {
        return 0;
    }//������п�������
    POINTF vs1 = {p1.x - p3.x, p1.y - p3.y}, vs2 = {p2.x - p3.x, p2.y - p3.y};
    POINTF vt1 = {p3.x - p1.x, p3.y - p1.y}, vt2 = {p4.x - p1.x, p4.y - p1.y};
    float s1v2, s2v2, t1v1, t2v1;
    //�����������ж���������
    if (Equal(s1v2 = vs1 ^ v2, 0) && p4 > p1 && p1 > p3) {
        Int = p1;
        return 2;
    }
    if (Equal(s2v2 = vs2 ^ v2, 0) && p4 > p2 && p2 > p3) {
        Int = p2;
        return 2;
    }
    if (Equal(t1v1 = vt1 ^ v1, 0) && p2 > p3 && p3 > p1) {
        Int = p3;
        return 2;
    }
    if (Equal(t2v1 = vt2 ^ v1, 0) && p2 > p4 && p4 > p1) {
        Int = p4;
        return 2;
    } //δ�������ϣ����ж��Ƿ��ཻ
    if(s1v2 * s2v2 > 0 || t1v1 * t2v1 > 0) {
        return 0;
    } //����Ϊ�ཻ��������㷨����ĵ�
    //�����������ʽ������������
    float ConA = p1.x * v1.y - p1.y * v1.x;
    float ConB = p3.x * v2.y - p3.y * v2.x;
    //��������ʽD1��D2��ֵ������ϵ������ʽ��ֵ���õ���������
    Int.x = (ConB * v1.x - ConA * v2.x) / Corss;
    Int.y = (ConB * v1.y - ConA * v2.y) / Corss;
    //��������1
    return 1;
}
// �Ƚ��������ĸ���x������(1, 0)�ļнǸ���
bool CompareVector(const POINTF &pt1, const POINTF &pt2) {
    //��������ģ
    float m1 = sqrt(pt1.x * pt1.x + pt1.y * pt1.y);
    float m2 = sqrt(pt2.x * pt2.x + pt2.y * pt2.y);
    //���������ֱ���(1, 0)���ڻ�
    float v1 = pt1.x / m1, v2 = pt2.x / m2;
    //��������н���ȣ��򷵻������Ͻ���һ������֤����
    return (v1 < v2 || v1 == v2 && m1 < m2);
}
//����͹��
bool CalcConvexHull(vector<POINTF> &Src) {
    //�㼯������Ӧ��3���㣬���ܹ��ɶ����
    if (Src.size() < 3) {
        return false;
    }
    //���һ���
    vector<POINTF>::iterator i;
    POINTF ptBase = Src.front(); //����1����Ԥ��Ϊ��С��
    for (i = Src.begin() + 1; i != Src.end(); ++i) {
        //�����ǰ���yֵС����С�㣬��yֵ��ȣ�xֵ��С
        if (i->y < ptBase.y || (i->y == ptBase.y && i->x > ptBase.x)) {
            //����ǰ����Ϊ��С��
            ptBase = *i;
        }
    }
    //�������������㹹�ɵ�����
    for (i = Src.begin(); i != Src.end();) {
        //�ų��������ͬ�ĵ㣬����������������г��ֳ�0����
        if (*i == ptBase) {
            i = Src.erase(i);
        }
        else {
            //�����ɻ��㵽Ŀ���
            i->x -= ptBase.x, i->y -= ptBase.y;
            ++i;
        }
    }
    //���������������֮��ļн�����
    sort(Src.begin(), Src.end(), &CompareVector);
    //ɾ����ͬ������
    Src.erase(unique(Src.begin(), Src.end()), Src.end());
    //�㼯�����ٻ�ʣ2���㣬���ϻ�����ܹ��ɶ����
    if (Src.size() < 2) {
        return false;
    }
    //����õ���β��������������
    for (vector<POINTF>::reverse_iterator ri = Src.rbegin();
        ri != Src.rend() - 1; ++ri) {
        vector<POINTF>::reverse_iterator riNext = ri + 1;
        //���������μ��㹫ʽ
        ri->x -= riNext->x, ri->y -= riNext->y;
    }
    //����ɾ������͹���ϵ�����
    for (i = Src.begin() + 1; i != Src.end(); ++i) {
        //����ɾ����ת�����෴��������ʹ������ж���ת����
        for (vector<POINTF>::iterator iLast = i - 1; iLast != Src.begin();) {
            float v1 = i->x * iLast->y, v2 = i->y * iLast->x;
            //����������0����û��������ת
            //����������0���������ڻ��жϷ����Ƿ�����
            if (v1 > v2 || (v1 == v2 && i->x * iLast->x > 0 &&
                i->y * iLast->y > 0)) {
                    break;
            }
            //ɾ��ǰһ������������µ�ǰ��������ǰ���������β����
            //���������μ��㹫ʽ
            i->x += iLast->x, i->y += iLast->y;
            iLast = (i = Src.erase(iLast)) - 1;
        }
    }
    //��������β���������������ۼӣ����������
    Src.front().x += ptBase.x, Src.front().y += ptBase.y;
    for (i = Src.begin() + 1; i != Src.end(); ++i) {
        i->x += (i - 1)->x, i->y += (i - 1)->y;
    }
    //��ӻ��㣬ȫ����͹���������
    Src.push_back(ptBase);
    return (Src.size() >= 3);
}
//����͹��������
float CalcArea(vector<POINTF> &Covex) {
    float fArea = 0;
    vector<POINTF>::iterator i, j;
    //���������ÿһ������
    for (i = Covex.begin(); i != Covex.end(); ++i) {
        //jΪi����һ������
        if ((j = i + 1) == Covex.end()) {
            j = Covex.begin();
        }
        //�ۼ����
        fArea += j->x * i->y - i->x * j->y;
    }
    return fArea / 2.0f;
}
//�ж����Ƿ��ڶ������
bool PointInPolygon(POINTF pt, vector<POINTF> &Poly) {
    //���������ÿһ������
    for (int i = 0; i < (int)Poly.size(); ++i) {
        //jΪi����һ������
        int j = (i + 1) % (int)Poly.size();
        //�����ɸ����㵽���������
        POINTF p1 = {pt.x - Poly[i].x, pt.y - Poly[i].y};
        //�����ɵ�ǰ���㵽��һ���������
        POINTF p2 = {Poly[j].x - Poly[i].x, Poly[j].y - Poly[i].y};
        //������������ж�
        float fCross = p1 ^ p2;
        if (fCross < 0) {
            return false;
        }
    }
    return true;
}

//������
int main(void) {
    vector<float> Result;
    //ѭ������ÿһ����������
    for (int nNum; cin >> nNum && nNum != 0; ++nNum) {
        vector<POINTF> Poly1, Poly2;
        for (POINTF pt; nNum-- > 0 && cin >> pt.x >> pt.y; Poly1.push_back(pt));
        cin >> nNum;
        for (POINTF pt; nNum-- > 0 && cin >> pt.x >> pt.y; Poly2.push_back(pt));
        //ȥ��ÿ��������У����ٵ��ظ���
        unique(Poly1.begin(), Poly1.end());
        unique(Poly2.begin(), Poly2.end());
        if (Poly1.size() < 3 || Poly2.size() < 3) {
            printf("%8.2f", 0.0f);
        }
        //����������ε������
        float fAreaUnion = CalcArea(Poly1);
        fAreaUnion += CalcArea(Poly2);
        vector<POINTF> IntPoly;
        //��Ӷ����1�ڶ����2�еĵ㵽������
        for (int i = 0; i < (int)Poly1.size(); ++i) {
            if (PointInPolygon(Poly1[i], Poly2)) {
                IntPoly.push_back(Poly1[i]);
            }
        }
        //��Ӷ����2�ڶ����1�еĵ㵽������
        for (int i = 0; i < (int)Poly2.size(); ++i) {
            if (PointInPolygon(Poly2[i], Poly1)) {
                IntPoly.push_back(Poly2[i]);
            }
        }
        //�������������еĽ��㣬���غϵĶ��㣬��ӵ�������
        for (int i = 0; i < (int)Poly1.size(); ++i) {
            for (int j = 0; j < (int)Poly2.size(); ++j) {
                POINTF Int;
                int nr = Intersection(
                    Poly1[i], Poly1[(i + 1) % (int)Poly1.size()],
                    Poly2[j], Poly2[(j + 1) % (int)Poly2.size()], Int);
                if (nr == 6) {
                    IntPoly.push_back(Poly1[i]);
                    IntPoly.push_back(Poly1[(i + 1) % (int)Poly1.size()]);
                }
                else if(nr > 0) {
                    IntPoly.push_back(Int);
                }
            }
        }
        //Ϊ������͹�������������
        float fIntArea = CalcConvexHull(IntPoly) ? CalcArea(IntPoly) * 2 : 0;
        //������
        Result.push_back(fAreaUnion - fIntArea);
    }
    //����ʽ������
    for (vector<float>::iterator i = Result.begin(); i != Result.end(); ++i) {
        printf("%8.2f", *i);
    }
    cout << endl;
    return 0;
}