% ---------
%u：ノットベクトル
%j：ノットスパンインデックス
%k：次数
%t：時間
function var = Calc_BasisFunc(u,j,k,t)
w1 = 0.0;
w2 = 0.0;

%このif文はu(j) < t && t <= u(j+1)と記述しているのでt == 0の場合が含まれないため
if t == 0
    if j == 1
        var = 1.0;
    else
        var = 0.0;
    end
else
    if k == 0 %（bj,0のばあい）u(j)とu(j+1)の間の値なら基底関数の値は1、それ以外なら0
        if u(j) < t && t <= u(j+1)
            var = 1.0;
        else
            var = 0.0;
        end
    else % 定義式に基づいた計算 再帰的に呼び出して計算している
        if (u(j+k+1)-u(j+1)) ~= 0  %「~=」はNOTイコールという意味　　ノットベクトルが多重節点の場所じゃない場合
            w1 = Calc_BasisFunc(u,j+1,k-1,t) * (u(j+k+1) - t)/(u(j+k+1)-u(j+1));
        end
        if (u(j+k)-u(j)) ~= 0
            w2 = Calc_BasisFunc(u,j,k-1,t) * (t - u(j))/(u(j+k) - u(j));
        end
        var = w1 + w2;
    end
end

end

265.2747