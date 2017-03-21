## 1. Elementare Kombinatorik

**1.4** k Auswahlen aus einer n-Menge

* geordnet mit Wiederholung $n^k$
* geordnet ohne Wiederholung $\frac{n!}{(n-k)!}$
* ungeordnet mit Wiederholung $\left( \begin{array}{c} n-k+1 \\ k \end{array} \right)$
* ungeordnet ohne Wiederholung $ \left( \begin{array}{c} n \\ k \end{array} \right) = \frac{n!}{(n-k)!k!}$

## 4. Klassische Wahrscheinlichkeitsverteilungen

* Hypergeometrische Verteilung: $P(A_k) = \frac{ | A_k | }{ | \Omega | } = \frac{\left( \begin{array}{c} s \\ k \end{array} \right)  \cdot \left( \begin{array}{c} r \\ n - k \end{array} \right) }{\left( \begin{array}{c} r+s \\ n \end{array} \right) }$
Erwartungswert $E(X) = n \cdot \frac{r}{r + s}$
* Binomialverteilung: $| A_k | = \left( \begin{array}{c} n \\ k \end{array} \right)  \cdot r^k \cdot s^{n-k}$
Erwartungswert $E(X) = n \cdot p \text{ , Varianz } Var(X) = n \cdot p \cdot q$
* Gemetrische Verteilung: $P(A_k) = p \cdot (1 -p)^{k-1}$
Erwartungswert $E(X) = n \cdot \frac{1}{p}$


## 5. Bedingte Wahrscheińlichkeit

**5.2 Satz und Definition**

* $P(A | B) = \frac{P(A \cap B)}{P(B)}$
* $P(E) = \displaystyle \sum_{k=1}^n P(E | A_k) \cdot P(A_k)$
* $P(A_m | E) = \frac{P(A_m) \cdot P(E | A_m)}{P(E)}$

## 6 Stochastische Unabhängigkeit

**6.1 Definition** $P(A \cap B) = P(A) \cdot P(B) \text{ oder } P(A) = P(A | B)$

## 7 Bernoulli-Ketten

**7.2** $P(E_k) = \left( \begin{array}{c} n \\ k \end{array} \right)  \cdot p^k \cdot (1 - p)^{n-k}$
**7.6.1** $B(n,p;k) = \frac{1}{\sigma} \cdot \varphi(\frac{k - \mu}{\sigma})$, wobei $\mu = n \cdot p, \sigma = \sqrt{n \cdot p \cdot q}, \varphi(x) = \frac{1}{\sqrt{2 \cdot \pi}} \cdot e^{- \frac{1}{2}x^2}$
> Bemerkungen: wenn $\sigma = 1 (标准方差)$， $B(n,p;k) = \varphi(k -\mu)$

**7.7.1** $\Phi = \frac{1}{\sqrt{2 \cdot \pi}} \cdot \int_{- \infty}^x e^{- \frac{1}{2}t^2} dt$
**7.7.2** $P(k_1 < k \leq k_2) = \Phi(\frac{k_2 - \mu + 0,5}{\sigma}) - \Phi(\frac{k_1 - \mu + 0,5}{\sigma})$
**7.8** $\lim_{n \to \infty} B(n,p;k) = \frac{\mu^k}{k!} \cdot e^{- \mu}$

## 9. Zufallsvariablen, Erwartungswert, Varianz

**9.6** Der Erwartungswert $E(X) = \displaystyle\sum_{w \in \Omega} X(\omega) \cdot P(\{ \omega \})$
**9.9** $E(a_1 X_1 + a_2 X_2 + ... + a_n X_n) = a_1 E(X_1) + ... +a_n E(X_n)$
**9.11** $E(g(x)) = \displaystyle\sum_{k=1}^m g(x_k) \cdot P(X = x_k)$
**9.13** $E(X \cdot Y) = E(X) \cdot E(Y)$
**9.14** $E(X - \mu) = 0$
**9.15** $Var(X) = E((X - \mu)^2)$
**9.20** $Var(X) = E((X - \alpha)^2) - (E(X) - \alpha)^2 \geq E((X - \mu)^2$
**9.21** $Var(X) = E(X^2) - \mu^2$
**9.22** $Var(\alpha \cdot X + \beta) = \alpha^2 \cdot Var(X)$
**9.24** $Var(\displaystyle\sum^m_{k=1} X_k) = \displaystyle\sum^m_{k=1}  Var(X_k)$
**9.33** $P(|X - \mu| \geq \varepsilon) \leq \frac{\sigma^2}{\varepsilon^2}$

## 10. Wahrscheinlichkeitsmaße mit Dichten

**10.14** $P(a < X \leq b) = \int\limits_a^b f(t)dt$
**10.15** Ist $X$ stetig, dann ist $P(a < X \leq b) = P(a < X < b) = P(a \leq X \leq b)$
**10.16** $\int\limits_\infty^{-\infty} F'(X)dx = 1$

## 11. Grenzwertsätze

**11.1** $P(|\frac{1}{n}(X_1+X_2+\dots+X_n) - \mu| \geq \varepsilon) \leq \frac{\sigma^2}{n \cdot \varepsilon^2}$
**11.2** $\lim_{n \to \infty} P(|\frac{X_1+X_2+\dots+X_n}{n} - \mu| < \varepsilon) = 1$
**11.3**  Schwaches Gesetz der großen Zahlen für Bernoulli-Experimente. $P(|\frac{X}{n} - p| \geq \varepsilon) \leq \frac{p(1-p)}{n \cdot \varepsilon^2}$
**11.6** $P(\lim\limits_{n \to \infty} H_n = p) = 1$
**11.7** $\lim\limits_{n \to \infty} P(a \leq \frac{X - n \cdot \mu}{\sigma \cdot \sqrt{n}} \leq b )= \lim\limits_{n \to \infty} P(a \leq \frac{H_n - p}{\sigma / \sqrt{n}} \leq b ) = \Phi(b) - \Phi(a)$
**11.8** $P(|H_n - p| \leq \varepsilon) \approx 2 \cdot \Phi(\varepsilon \cdot \sqrt{\frac{n}{p \cdot q}}) - 1 = 2 \cdot \Phi(\frac{\varepsilon}{\sigma / \sqrt{n}}) - 1$

## 12. Parameterschätzung
**12.5** $E(\tau_n) = E(H_n) = p  = \Theta$

1. Vertrauensniveau $\gamma$
2. $p(-c \leq \frac{\overline{X} - \mu}{\sigma / \sqrt{n}} \leq c) = \gamma \iff \Phi(c) = \frac{\gamma + 1}{2}$
3. $\overline{x} - c \cdot \frac{\sigma}{\sqrt{n}} \leq \mu \leq \overline{x} + c \cdot \frac{\sigma}{\sqrt{n}}$


## 13. Regression
1. $f(x) = m \cdot x, m = \displaystyle\sum^n_{i=1} x_i y_i / \displaystyle\sum^n_{i=1} x^2_i$
2. $f(x) = ax + b, a = \displaystyle\sum^n_{i=1} x_i y_i - n \overline{x} \overline{y} / \displaystyle\sum^n_{i=1} x^2_i - n \overline{x}^2, b = \overline{y} - a \overline{x}$
