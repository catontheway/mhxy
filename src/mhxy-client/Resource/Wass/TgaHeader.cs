// FileName:  TgaHeader.cs
// Author:  guodp <guodp9u0@gmail.com>
// Create Date:  20180207 17:27
// Description:   

namespace mhxy.Resource.Wass {

    /// <summary>
    ///     Tga 文件头
    /// </summary>
    public class TgaHeader {

        public byte IdLength;
        public byte ColorMapType;
        public byte ImageType;
        public ushort ColorMapFirstIndex;
        public ushort ColorMapLength;
        public byte ColorMapEntrySize;
        public ushort XOrigin;
        public ushort YOrigin;
        public ushort ImageWidth;
        public ushort ImageHeight;
        public byte PixelDepth;
        public byte ImageDescruptor;

    }

}