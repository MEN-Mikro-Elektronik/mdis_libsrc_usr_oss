<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="page">
    <filename>index</filename>
    <title></title>
    <name>index</name>
  </compound>
  <compound kind="file">
    <name>delay.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>delay_8c</filename>
    <member kind="function">
      <type>int32</type>
      <name>UOS_Delay</name>
      <anchor>a0</anchor>
      <arglist>(u_int32 msec)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>dl_list.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>dl__list_8c</filename>
    <member kind="function">
      <type>UOS_DL_LIST *</type>
      <name>UOS_DL_NewList</name>
      <anchor>a0</anchor>
      <arglist>(UOS_DL_LIST *l)</arglist>
    </member>
    <member kind="function">
      <type>UOS_DL_NODE *</type>
      <name>UOS_DL_Remove</name>
      <anchor>a1</anchor>
      <arglist>(UOS_DL_NODE *n)</arglist>
    </member>
    <member kind="function">
      <type>UOS_DL_NODE *</type>
      <name>UOS_DL_RemHead</name>
      <anchor>a2</anchor>
      <arglist>(UOS_DL_LIST *l)</arglist>
    </member>
    <member kind="function">
      <type>UOS_DL_NODE *</type>
      <name>UOS_DL_AddTail</name>
      <anchor>a3</anchor>
      <arglist>(UOS_DL_LIST *l, UOS_DL_NODE *n)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>errno.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>errno_8c</filename>
    <member kind="function">
      <type>u_int32</type>
      <name>UOS_ErrnoGet</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>u_int32</type>
      <name>UOS_ErrnoSet</name>
      <anchor>a1</anchor>
      <arglist>(u_int32 errCode)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>errstr.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>errstr_8c</filename>
    <member kind="function">
      <type>char *</type>
      <name>UOS_ErrString</name>
      <anchor>a0</anchor>
      <arglist>(int32 errCode)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>UOS_ErrStringTs</name>
      <anchor>a1</anchor>
      <arglist>(int32 errCode, char *strBuf)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ident.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>ident_8c</filename>
    <member kind="function">
      <type>char *</type>
      <name>UOS_Ident</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>key.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>key_8c</filename>
    <member kind="function">
      <type>int32</type>
      <name>UOS_KeyPressed</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>UOS_KeyWait</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>mdelay.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>mdelay_8c</filename>
    <member kind="function">
      <type>int32</type>
      <name>UOS_MikroDelayInit</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>UOS_MikroDelay</name>
      <anchor>a5</anchor>
      <arglist>(u_int32 usec)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>random.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>random_8c</filename>
    <member kind="function">
      <type>u_int32</type>
      <name>UOS_Random</name>
      <anchor>a0</anchor>
      <arglist>(u_int32 old)</arglist>
    </member>
    <member kind="function">
      <type>u_int32</type>
      <name>UOS_RandomMap</name>
      <anchor>a1</anchor>
      <arglist>(u_int32 val, u_int32 ra, u_int32 re)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>signal.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>signal_8c</filename>
    <member kind="function">
      <type>int32</type>
      <name>UOS_SigInit</name>
      <anchor>a5</anchor>
      <arglist>(void(*sigHandler)(u_int32 sigCode))</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>UOS_SigExit</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>UOS_SigInstall</name>
      <anchor>a7</anchor>
      <arglist>(u_int32 sigCode)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>UOS_SigRemove</name>
      <anchor>a8</anchor>
      <arglist>(u_int32 sigCode)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>UOS_SigMask</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>UOS_SigUnMask</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>UOS_SigWait</name>
      <anchor>a11</anchor>
      <arglist>(u_int32 msec, u_int32 *sigCodeP)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>timer.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/</path>
    <filename>timer_8c</filename>
    <member kind="function">
      <type>u_int32</type>
      <name>UOS_MsecTimerGet</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>u_int32</type>
      <name>UOS_MsecTimerResolution</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>usr_oss_specification.c</name>
    <path>/opt/menlinux/LIBSRC/USR_OSS/COM/</path>
    <filename>usr__oss__specification_8c</filename>
    <member kind="function">
      <type>u_int32</type>
      <name>UOS_ErrnoGet</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>u_int32 __MAPILIB</type>
      <name>UOS_ErrnoSet</name>
      <anchor>a1</anchor>
      <arglist>(u_int32 error)</arglist>
    </member>
    <member kind="function">
      <type>char *__MAPILIB</type>
      <name>UOS_ErrString</name>
      <anchor>a2</anchor>
      <arglist>(int32 errCode)</arglist>
    </member>
    <member kind="function">
      <type>char *__MAPILIB</type>
      <name>UOS_ErrStringTs</name>
      <anchor>a3</anchor>
      <arglist>(int32 errCode, char *strBuf)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_Delay</name>
      <anchor>a4</anchor>
      <arglist>(u_int32 msec)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_MikroDelayInit</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_MikroDelay</name>
      <anchor>a6</anchor>
      <arglist>(u_int32 usec)</arglist>
    </member>
    <member kind="function">
      <type>u_int32 __MAPILIB</type>
      <name>UOS_MsecTimerGet</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>u_int32 __MAPILIB</type>
      <name>UOS_MsecTimerResolution</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_SigInit</name>
      <anchor>a9</anchor>
      <arglist>(void(*sigHandler)(u_int32 sigCode))</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_SigExit</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_SigInstall</name>
      <anchor>a11</anchor>
      <arglist>(u_int32 sigCode)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_SigRemove</name>
      <anchor>a12</anchor>
      <arglist>(u_int32 sigCode)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_SigMask</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_SigUnMask</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_SigWait</name>
      <anchor>a15</anchor>
      <arglist>(u_int32 msec, u_int32 *sigCodeP)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_KeyPressed</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int32 __MAPILIB</type>
      <name>UOS_KeyWait</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>u_int32 __MAPILIB</type>
      <name>UOS_Random</name>
      <anchor>a18</anchor>
      <arglist>(u_int32 old)</arglist>
    </member>
    <member kind="function">
      <type>u_int32 __MAPILIB</type>
      <name>UOS_RandomMap</name>
      <anchor>a19</anchor>
      <arglist>(u_int32 val, u_int32 ra, u_int32 re)</arglist>
    </member>
    <member kind="function">
      <type>char *__MAPILIB</type>
      <name>UOS_Ident</name>
      <anchor>a20</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>UOS_DL_LIST *__MAPILIB</type>
      <name>UOS_DL_NewList</name>
      <anchor>a21</anchor>
      <arglist>(UOS_DL_LIST *l)</arglist>
    </member>
    <member kind="function">
      <type>UOS_DL_NODE *__MAPILIB</type>
      <name>UOS_DL_Remove</name>
      <anchor>a22</anchor>
      <arglist>(UOS_DL_NODE *n)</arglist>
    </member>
    <member kind="function">
      <type>UOS_DL_NODE *__MAPILIB</type>
      <name>UOS_DL_RemHead</name>
      <anchor>a23</anchor>
      <arglist>(UOS_DL_LIST *l)</arglist>
    </member>
    <member kind="function">
      <type>UOS_DL_NODE *__MAPILIB</type>
      <name>UOS_DL_AddTail</name>
      <anchor>a24</anchor>
      <arglist>(UOS_DL_LIST *l, UOS_DL_NODE *n)</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>ossdummy</name>
    <title>MEN logo</title>
    <filename>ossdummy</filename>
  </compound>
  <compound kind="page">
    <name>linuossigusage</name>
    <title></title>
    <filename>linuossigusage</filename>
  </compound>
  <compound kind="page">
    <name>usrosscommonspec</name>
    <title>USR_OSS specificiation MDIS5</title>
    <filename>usrosscommonspec</filename>
  </compound>
  <compound kind="page">
    <name>uossigusage</name>
    <title>Using USR_OSS Signals</title>
    <filename>uossigusage</filename>
  </compound>
  <compound kind="page">
    <name>uosdllusage</name>
    <title>Using USR_OSS Double Linked Lists</title>
    <filename>uosdllusage</filename>
  </compound>
</tagfile>
