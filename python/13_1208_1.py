#! /usr/bin/env python
# -*- coding: utf-8 -*-
import wx

def main():
    application = wx.App()
    frame = wx.Frame(None, wx.ID_ANY, 'TEST')
    frame.SetBackgroundColour('#000000')
    frame.Size = (500, 400)
    frame.Centre()
    frame.CreateStatusBar()
    SetFrame(frame)
    frame.Show()
    application.MainLoop()

def SetFrame(frame):
    panel = wx.Panel(frame, wx.ID_ANY)
    panel.Size = (10, 20)
    panel.Centre()
    panel.SetBackgroundColour('#5FAA0C')
    apanel = wx.Panel(frame, wx.ID_ANY, pos=(0, 0))
    apanel.Size = (10, 20)
    apanel.SetBackgroundColour('#FF1111')
    
if __name__ == '__main__':
    main()
