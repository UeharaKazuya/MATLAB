%------------ 説明 --------------
%今の独立変数uが（u∈[0 1]）の範囲においてどのノットとノットの間にいるか
%計算するもの
%------------ 入力 --------------
%u：時間変数
%U：ノットベクトル
%p：スプラインの次数
%--------------------------------
%------------ 出力 --------------
%Span_index：Uを含むノットスパンのインデックス（U(Span_index) <= u < U(Span_index+1)）
%Span_index = 1の場合は特殊なので基底関数の計算では分けて処理
%--------------------------------
function Span_index = WhichSpan(u,U,p)
    if u == 1
        i_lower  = length(U)-(p+1);%限りなく1に近い値と扱うことにした u ≒ 1のときノットスパンiは U(i) <= u < 1のU(i)のインデックス
        i_higher = i_lower;
    else
        i_lower  = find(U <= u,1,'last');
        i_higher = find(u < U,1,'first');
    
        %インデックスが計算できているかチェックするやつ
        lower_than_u  = U(i_lower);
        higher_than_u = U(i_higher);
    end
    Span_index = i_lower;
end