**Formel**

- Die Lösungen zu $a^2 + bx +c = 0 $ ist $x_{1,2} = \frac{-b \pm \sqrt{b^2-4ac}}{2a}$
- $Z^n=r(cos\varphi+sin\varphi i) \Rightarrow Z_k = \sqrt[n]{r}(cos\frac{\varphi+2\pi k}{n} + sin\frac{\varphi+2\pi k}{n} i)$
- $\int u(x)v'(x) = u(x)v(x) - \int u'(x)v(x)$
- $f(x)\approx \frac{f(x_0)}{0!} + \frac{f(x - x_0)}{1!} + \frac{f(x - x_0)^2}{2!} + \frac{f(x - x_0)^3}{3!} + ...$
- $sin(x) = \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n+1)!}x^{2n+1} \qquad \forall x \in R$
- $sin \alpha \cdot cos \beta = \frac{1}{2} \{ sin( \alpha - \beta ) + cos( \alpha + \beta ) \};$
- $sin 2\alpha = 2sin\alpha \cdot cos\alpha;$
- $\sum_{n=0}^{\infty}b\cdot q^n=b\cdot\frac{1}{1-q}$
- $\sum_{k=0}^{\infty}\frac{1}{k^{\alpha}}, \alpha \leq 1 \; div,\alpha > 1 \; konv. $

------

**Notwendiges Konvergenkriterium**

- $\sum_{k=1}^{\infty}|a_k| \; konv. \Rightarrow \sum_{k=1}^{\infty}a_k \; konv.$
- $\sum_{k=1}^{\infty}a_k \neq 0 \Rightarrow \sum_{k=0}^{\infty} a_k,\sum_{k=0}^{\infty} |a_k| \; divergent$
- **Majorantenkriterium**
	- $0 ≤ a_k ≤ b_k$, Dann gilt: $\sum_{k=0}^{\infty} b_k \; konv. \Rightarrow \sum_{k=0}^{\infty} a_k \; konv.$
- **Minorantenkriterium**
	- $0 ≤ a_k ≤ b_k$, Dann gilt: $\sum_{k=0}^{\infty} b_k \; div. \Rightarrow \sum_{k=0}^{\infty} a_k \; div.$
- **Grenzwertkriterium**
	- Für $\sum_{k=0}^{\infty} a_k $ und $\sum_{k=0}^{\infty} b_k $, existiert $q = \lim_{n \rightarrow \infty} \frac{a_k}{b_k} > 0$, dann sind gleichzeitig beide Reihen konvergent oder divergent.
- **Quotientenkriterium**
	- $\sum_{k=1}^{\infty} a_k, a_k \neq 0 $, es gilt: Existiert$ q = \lim_{n \rightarrow \infty} \frac{|a_{k+1|}}{|a_k|}$,dann ist die Reihen$\sum_{k=1}^{\infty}a_k, \sum_{k=1}^{\infty}|a_k|$:
        1. konvergent, falls q < 1
        2. divergent, falls q > 1
        3. keine Entscheidung, falls q = 1
- **Wurzelkriterium**
	- $\sum_{k=1}^{\infty} a_k, a_k \neq 0$, es gilt: $ \exists q = \lim_{n \rightarrow \infty} \sqrt[k]{|a_k|}$,dann sind die Reihen  $\sum_{k=1}^{\infty} a_k, \sum_{k=1}^{\infty} |a_k|$:
        1. konvergent, falls q < 1
        2. divergent, falls q > 1
        3. keine Entscheidung, falls q = 1
- **Leibniz’sche Regel**
	- Sei $ \sum_{k=1}^{\infty}(-1)^{k+1} \cdot a_k \;mit\; a_{k+1} < a_k, \lim_{k \rightarrow \infty} = 0 $
      Dann gilt: $\sum_{k=1}{\infty}(-1)^{k+1} \cdot a_k \; konv. , |r_n| < a_{n+1}$
