import pandas as pd
import matplotlib.pyplot as plt
import glob
import os
import numpy as np

print("\n" + "="*50)
print(" HE THONG PHAN TICH TOAN DIEN: DOI LAP VA KY VONG")
print("="*50)

script_dir = os.path.dirname(os.path.abspath(__file__))
data_dir = os.path.join(script_dir, '..', 'data')
file_list = glob.glob(os.path.join(data_dir, 'data_*.csv'))

if not file_list:
    print(f"LOI: khong tim thay du lieu tai: {data_dir}")
    print("Vui long chay file C++ truoc de sinh du lieu.")
    exit()

all_dfs = []
max_rounds = 0

print(f"[1/3] dang xu ly {len(file_list)} luong du lieu...")
for f in file_list:
    df = pd.read_csv(f)
    all_dfs.append(df)
    max_rounds = max(max_rounds, df['Van'].max())

van_range = np.arange(1, max_rounds + 1)
sum_von_gapthep = np.zeros(max_rounds)
sum_von_antoan = np.zeros(max_rounds)

for df in all_dfs:
    v_gt = df['Von_GapThep'].values
    v_at = df['Von_AnToan'].values
    
    sum_von_gapthep[:len(v_gt)] += v_gt
    sum_von_antoan[:len(v_at)] += v_at

mean_gapthep = sum_von_gapthep / len(all_dfs)
mean_antoan = sum_von_antoan / len(all_dfs)


file_info = sorted([(f, len(pd.read_csv(f))) for f in file_list], key=lambda x: x[1])
df_short = pd.read_csv(file_info[0][0])
df_long = pd.read_csv(file_info[-1][0])


fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(15, 18), layout="constrained")

ax1.plot(df_short['Van'], df_short['Von_GapThep'], color='#d62728', label='Gấp Thếp', linewidth=1.5)
ax1.plot(df_short['Van'], df_short['Von_AnToan'], color='#1f77b4', label='An Toàn', alpha=0.6)
ax1.set_title(f"KỊCH BẢN 1: PHÁ SẢN SIÊU TỐC ({len(df_short):,} ván)", 
              fontsize=16, fontweight='bold', color='red', pad=15)
ax1.legend(loc='upper right')


ax2.plot(df_long['Van'], df_long['Von_GapThep'], color='#d62728', label='Gấp Thếp', linewidth=1.2)
ax2.plot(df_long['Van'], df_long['Von_AnToan'], color='#1f77b4', label='An Toàn', alpha=0.6)
ax2.set_title(f"KỊCH BẢN 2: MAY MẮN TRỤ LẠI LÂU NHẤT ({len(df_long):,} ván)", 
              fontsize=16, fontweight='bold', color='green', pad=15)
ax2.legend(loc='upper right')


ax3.plot(van_range, mean_gapthep, color='#d62728', linewidth=2.5, label='Kỳ vọng Gấp Thếp')
ax3.plot(van_range, mean_antoan, color='#1f77b4', linewidth=2.5, label='Kỳ vọng An Toàn')

ax3.fill_between(van_range, mean_gapthep, color='#d62728', alpha=0.1)
ax3.set_title("KỊCH BẢN 3: ĐƯỜNG CONG KỲ VỌNG TRUNG BÌNH (EV)", 
              fontsize=16, fontweight='bold', color='purple', pad=15)
ax3.set_xlabel("Số lượng ván cược", fontsize=12)


for ax in [ax1, ax2, ax3]:
    ax.axhline(0, color='black', linestyle='-', linewidth=1.5) 
    ax.set_ylabel("Số dư trong ví (VNĐ)", fontsize=12)
    ax.grid(True, linestyle=':', alpha=0.5)


fig.suptitle('TỪ BIẾN ĐỘNG NGẪU NHIÊN ĐẾN QUY LUẬT TOÁN HỌC TẤT YẾU', 
             fontsize=22, fontweight='bold')

print("[3/3] Hoan tat! Bieu do da duoc hien thi.")
plt.show()