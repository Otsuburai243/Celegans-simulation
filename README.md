# Celegans-simulation
Simulation of the C. elegans olfactory neural circuit using a nonlinear model.

## 1.1 研究目的 (Research Objective)

### [Japanese]
癌患者特有の匂いは臨床現場では経験則的に信じられてきた．しかし，そのような癌特有の匂い物質は現在も特定されていない．もし，そのような癌の匂いをかぎ分けることができたなら，既存の癌検査キットより安価で高精度な診断となる可能性がある．癌の匂いの判断を機器分析ではなく，生物の嗅覚によって行おうとする試みはかねてから行われている．中でも嗅覚に優れた犬を用いた，癌探知犬は世界各地で研究が進められている．癌探知犬は癌患者の尿や呼気，体臭，血液などを検体として識別が可能である．しかし，長期的な訓練や，集中力の問題により１日の検体数に限りが ある．また，飼育コストなどから実用化は困難であるといえる．

犬以外の生物では，線虫 C.elegans が癌特有の匂いを感知できる可能性が示唆された．C.elegans の嗅覚受容体は，全生物中アフリカゾウに次いで２番目に多く，少量の匂い物質でも感知できる．加えて，線虫は匂いを受容する嗅覚神経細胞が AWA, AWB, AWC, ASH, ASL の５種類であり，左右に１対存在するため細胞数が１０個しかなく，解析が容易である．

先行研究では，健常者と癌患者の尿サンプルから，線虫が癌を識別できるかの実験が行われた．この実験から，高い確率で線虫が癌患者の尿サンプルに誘引行動を示すことが判明した．また，嗅覚神経細胞の中で AWC 神経細胞のみが活動状態が高かったことから，AWC 神経細胞が癌の識別に重要な役割を担っていること，癌由来物質が揮発性物質であることが示唆された．この実験では約 97%の確率で AWC 神経細胞の活動状態が高まったのに対し，線虫が誘引行動を示したのは約 86%であり，細胞ベースで観測した場合と行動ベースでの観測した場合での差について着目した．

本研究では，非線形な数理モデルにより膜電位の時間変化シミュレーションを行い，癌細胞由来揮発性物質の匂い刺激に対しての神経回路の考察を行う．AWC 神経細胞と線虫の誘引行動の関係を考察し精度に差が生じることの説明を目的とする．

---

### [English]
The existence of a specific odor associated with cancer patients has long been empirically believed in clinical settings; however, the specific odorant molecules remain unidentified. If such cancer-specific odors could be detected, it could lead to more affordable and highly accurate diagnostics compared to existing cancer screening kits. Attempts to use biological olfaction, rather than instrumental analysis, to determine cancer odors have been ongoing. Among these, research on cancer-sniffing dogs, utilizing their superior sense of smell, is being conducted worldwide. These dogs can identify cancer using samples such as urine, breath, body odor, and blood. However, practical application is difficult due to the limits on the number of samples processed per day caused by long-term training and concentration issues, as well as high breeding costs.

As an alternative to dogs, it has been shown that the nematode *C. elegans* might be able to detect cancer-specific odors. *C. elegans* has the second highest number of olfactory receptors among all organisms, next only to the African elephant, allowing it to detect even minute amounts of odorants. In addition, the nematode has only five types of olfactory neurons that receive odors (AWA, AWB, AWC, ASH, ASL), and since they exist in pairs (left and right), there are only 10 cells in total, making computational analysis highly feasible.

Experiments have demonstrated that nematodes can distinguish cancer using urine samples from healthy individuals and cancer patients. These experiments revealed that nematodes exhibit attractive behavior toward urine samples from cancer patients with a high probability. Furthermore, since only the AWC neuron showed high activity among the olfactory neurons, it is suggested that the AWC neuron plays a crucial role in identifying cancer and that the cancer-derived substance is volatile. While the activity of the AWC neuron increases with a probability of about 97% in these observations, the nematodes actually show attractive behavior at a rate of about 86%. This study focuses on this discrepancy between cell-based observation and behavior-based observation.

In this research, based on this specific neuronal group (Fig. 1), we perform a time-series simulation of membrane potential using a nonlinear mathematical model to examine the neural circuit's response to odor stimulation from cancer-derived volatile substances. The objective is to analyze the relationship between AWC neurons and the attractive behavior of nematodes, thereby explaining the difference in accuracy.
